#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <charm++.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <time.h>

#include "data_balancing.decl.h"

CProxy_Main mainProxy;
CProxy_DataInstance dataArray;

//represent the size of the array AKA number of chares in the array 
int arraySize; 

//represents lower and upper bounds for the number of elements that will be in each chare
int lowerBound; 
int upperBound; 

class Main : public CBase_Main {
    private:
        int* chareSizes; 

        struct ChareInfo {
            int index;
            int size;
            int surplus;
            int deficit;
        };

        struct PlanStructure {
            std::vector<std::pair<int, int>> receivers; 
            int expectedReceives; 
            int expectedSends; 
        };

        std::vector<PlanStructure> overallPlan;
    public: 
        Main(CkArgMsg* m) {
            srand(time(NULL));
            
            //command line parsing
            arraySize = 8; 
            lowerBound = 1; 
            upperBound = 20; 
            if (m->argc != 4 && m->argc != 1) {
                CkPrintf("%s: incorrect number of arguments provided\n", m->argv[0]);
            }
            
            if (m->argc == 4) {
                arraySize = atoi(m->argv[1]);
                lowerBound = atoi(m->argv[2]); 
                upperBound = atoi(m->argv[3]);
            }
            delete m;

            mainProxy = thisProxy;

            //starting data balancing
            dataArray = CProxy_DataInstance::ckNew(arraySize);
            dataArray.sendSizes(); //reduction that send sizes of all the chares to the calcRedistribution function
        }

        void calcRedistributionPlan(int charesizes[arraySize]) {
            chareSizes = charesizes; 
            //first calculate the total number of elements 
            int totalNumElements = 0; 
            for (int i = 0; i < arraySize; i++) {
                totalNumElements += chareSizes[i];
            }
            CkPrintf("Main Chare received chare sizes. Total Size = %d. Creating Redistribution Plan\n", totalNumElements);

            //calculate the desired load for each chare
            int desiredLoad = totalNumElements / arraySize; 
            int remainder = totalNumElements % arraySize; //the number of chares that will have an extra element 

            
            std::vector<ChareInfo> chareInfos(arraySize);
            for (int i = 0; i < arraySize; i++) {
                chareInfos[i].index = i;
                chareInfos[i].size = chareSizes[i];
                
                int desired = desiredLoad + (remainder > 0 ? 1 : 0);
                if (remainder > 0) {
                    remainder--; 
                }
                int diff = chareInfos[i].size - desired; 
                chareInfos[i].surplus = std::max(diff, 0);
                chareInfos[i].deficit = -1 * std::min(diff, 0);
            }

            //starting to populate the plan
            
            overallPlan = std::vector<PlanStructure>(arraySize);
            for (size_t i = 0; i < arraySize; i++) {
                overallPlan[i].expectedReceives = chareInfos[i].deficit; 
                overallPlan[i].expectedSends = chareInfos[i].surplus; 
                overallPlan[i].receivers = std::vector<std::pair<int, int>>();
            }
            int surplusIdx = 0;
            int deficitIdx = 0;
            while (surplusIdx < arraySize && deficitIdx < arraySize) {
                //find a chare with surplus and a chare with deficit
                while (surplusIdx < arraySize && chareInfos[surplusIdx].surplus == 0) {
                    surplusIdx++; 
                }
                while (deficitIdx < arraySize && chareInfos[deficitIdx].deficit == 0) {
                    deficitIdx++;
                }
                //edge case probably?
                if (surplusIdx >= arraySize || deficitIdx >= arraySize) {
                    break;
                }
                int transferAmount = std::min(chareInfos[surplusIdx].surplus,
                                      chareInfos[deficitIdx].deficit);

                chareInfos[surplusIdx].surplus -= transferAmount;
                chareInfos[deficitIdx].deficit -= transferAmount;

                overallPlan[surplusIdx].receivers.push_back(std::make_pair(deficitIdx, transferAmount));
            }
            // Print the redistribution plan
            // CkPrintf("Redistribution Plan:\n");
            // for (int i = 0; i < arraySize; i++) {
            //     CkPrintf("Chare %d has size %d and will send to: ", i, chareInfos[i].size);
            //     for (const auto& receiver : overallPlan[i].receivers) {
            //         CkPrintf("(Chare %d, Amount %d) ", receiver.first, receiver.second);
            //     }
            //     CkPrintf(" | Expected Sends: %d, Expected Receives: %d", overallPlan[i].expectedSends, overallPlan[i].expectedReceives);
            //     CkPrintf("\n");
            // }

            //first send the expectedSends and expectedReceives to each chare
            //Originally i had them sent at teh same time, but i didn't realize but this is a race condition, if the surplus chare pushes before the chare get's to the execptedSends, the expectedRecevie will still be 0 which is not what we want 
            for (int i = 0; i < arraySize; i++) {
                dataArray[i].sendExpectedSendsReceives(overallPlan[i].expectedSends, overallPlan[i].expectedReceives);
            }
        }

        void sendRedistributionPlan(int finished) {
            //now we have the plan, we turn it into a form that we can send off to the chares 
            for (int i = 0; i < arraySize; i++) {
                int n = (overallPlan[i].receivers.size() * 2) + 2; //plus expectedSends and expectedReceives 
                int plan[n];
                int idx = 0;
                for (size_t j = 0; j < overallPlan[i].receivers.size(); j++) {
                    plan[idx++] = overallPlan[i].receivers[j].first;
                    plan[idx++] = overallPlan[i].receivers[j].second;
                }
                plan[n - 2] = overallPlan[i].expectedSends;
                plan[n - 1] = overallPlan[i].expectedReceives;

                //send individaulized plan to each chare 
                dataArray[i].redistribute(n, plan);
            }
        }

        //need this function to know when all chares are done so we can Ckexit(). The only way i thought of doing this is through reduction, is there another way?
        void charesFinished(int finished) {
            CkPrintf("Data has been balanced! Ending the program...\n");
            CkExit();
        }
};

class DataInstance : public CBase_DataInstance {
    private:
        //the actual numbers it stores
        std::vector<int> numbers; 

        int expectedReceives;
        int expectedSends; 

        int receivedCount; 
        int sendCount; 

        //sizes of the chares, necessary for reduction. Is there another way to do this?
        int* chare_sizes; 

    public: 
        DataInstance() {
            //initialize each chare with a vector of random size inclusive of lower and upper bound 
            srand(time(0) + thisIndex);
            int numElements = rand() % (upperBound - lowerBound + 1) + lowerBound;
            for (int i = 0; i < numElements; i++) {
                numbers.push_back((rand() % 10000) + 1); //send upper bound number to be 10000
            }

            expectedReceives = 0;
            expectedSends = 0;
            receivedCount = 0; 
            sendCount = 0; 

            //create an array of size 2*ar
            chare_sizes = new int[arraySize];
            for (int i = 0; i < arraySize; i++) {
                chare_sizes[i] = 0;
            }

            printChareContent();
        }

        //performs reduction to calculate size of chares 
        void sendSizes() {
            chare_sizes[thisIndex] = numbers.size();
            CkCallback cb(CkReductionTarget(Main, calcRedistributionPlan), mainProxy);
            contribute(sizeof(int) * arraySize, chare_sizes, CkReduction::sum_int, cb);
        }

        //this chare is to synchronize and make sure each chare receives their expectedSends and expectedReceives before starting the redistribution
        void sendExpectedSendsReceives(int ev_sends , int ev_recvs) {
            expectedSends = ev_sends;
            expectedReceives = ev_recvs;
            int one = 1; 
            CkCallback cb(CkReductionTarget(Main, sendRedistributionPlan), mainProxy);
            contribute(sizeof(int), &one, CkReduction::sum_int, CkCallback(CkReductionTarget(Main, sendRedistributionPlan), mainProxy));
        }

        void redistribute(int n, int plan[n]) {
            //specific plan for a chare
            
            //populate expectedreceives and expectedsends - need this to check when this chare is done
            expectedSends = plan[n - 2];
            expectedReceives = plan[n - 1];
            //not sending or receiving anything 
            if (expectedReceives == 0 && expectedSends == 0) {
                ChareDone();
                return;
            }

            //if this chare has a surplus and needs to send stuff
            if (expectedSends) {
                for (size_t i = 0; i < n - 2; i+=2) {
                    int target = plan[i];
                    int amount = plan[i + 1];
                    std::vector<int> dataToSend;
                    for (int i = 0; i < amount; i++) {
                        int data = numbers.back();
                        numbers.pop_back();
                        dataToSend.push_back(data);
                    }
                    
                    //CkPrintf("Chare %d is sending %d elements to Chare %d\n", thisIndex, amount, target);

                    dataArray[target].pushData(dataToSend.size(), dataToSend.data());
                }
                ChareDone();
            }
            //deficit case will be handled in pushData
        }

        void pushData(int n, int data[n]) {
            //CkPrintf("Chare %d before has received %d elements and expectedReceives: %d\n", thisIndex, receivedCount, expectedReceives);
            for (size_t i = 0; i < n; i++) {
                numbers.push_back(data[i]);
            }
            receivedCount += n;
            //CkPrintf("Chare %d now has %d elements\n", thisIndex, receivedCount);
            if (receivedCount == expectedReceives) {
                ChareDone();
            }
        }

        void ChareDone() {
            printChareContent();
            
            //this reduction is used to synchronize all chares to know when they are all done
            int one = 1;
            CkCallback cb(CkReductionTarget(Main, charesFinished), mainProxy);
            contribute(sizeof(int), &one, CkReduction::sum_int, CkCallback(CkReductionTarget(Main, charesFinished), mainProxy));
        }

        void printChareContent() {
            std::string output; 
            output += "Chare " + std::to_string(thisIndex) + ": [";
            for (int i = 0; i < numbers.size(); i++) {
                output += std::to_string(numbers[i]);
                if (i < numbers.size() - 1) {
                    output += ", ";
                }
            }
            output += "]\n";
            CkPrintf("%s", output.c_str());
        }
};


#include "data_balancing.def.h"