#include "oddeven.decl.h"
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <random>
#include <stdio.h>
#include <stdio.h>
#include <utility>
#include <iostream>
#include <assert.h>

CProxy_Main mainProxy;
CProxy_sortchare array;
int numElements; 

class MsgData : public CMessage_MsgData {
    public: 
        double value; 
        int index; 
};

class Main : public CBase_Main {
    private: 
        int numsReceived;
    public:
        Main(CkArgMsg* msg) {
            if (msg->argc < 2) {
                CkPrintf("Usage: ./charmrun +p<n> ./oddeven N\n");
                CkExit();
            }
            
            numsReceived = 0; 
            numElements = atoi(msg->argv[1]);
            mainProxy=thisProxy;

            if (numElements == 1) {
                CkPrintf("Only one element. Nothing to sort.\n");
                CkExit();
            }

            array = CProxy_sortchare::ckNew(numElements);
            array.run();
        }
        
        void done() {
            numsReceived += 1;
            //even chares are doing all the work so we only need to wait for half of the elements to be done
            if (numsReceived == numElements / 2) {
                CkPrintf("Sorting Done. Final Array: \n");
                numsReceived = 0; 
                array.print_endmynum();
            }
        }

        void secondDone() {
            CkPrintf("Second Reduction is done\n");
            CkExit();
        }
};


class sortchare: public CBase_sortchare
{
    private:
        double myval;
        int index; 
        int step; //0 means even, 1 means odd 

        struct BufferedMessage {
            int idx; 
            double value; 
            CkFuture future; 
        };

        std::vector<BufferedMessage> buffer; 

    public:
        sortchare() {
            srand48(time(NULL) + thisIndex);

            //all chares start off with a random value 
            myval= drand48();
            index = thisIndex; 
            print_startmynum();

            //all chares start off at the even step 
            step=0;
        }

        void run() {
            //even chares will be responsbile for sending and receiving their values 
            if (thisIndex % 2 == 0) {
                for (int i = 0; i < numElements / 2; i++) {
                    //even step -> even chares send their values to right neighbor 
                    if (thisIndex + 1 < numElements) {
                        CkFuture future = CkCreateFuture();
                        thisProxy[thisIndex + 1].receiveValue(index, myval, future);
                        MsgData* msg = (MsgData*)CkWaitFuture(future);
                        //CkPrintf("[chare %d] Got future\n", thisIndex);
                        myval = msg->value; 
                        step = (step+1);

                        // delete future; 
                        // delete msg; 
                    } else { //this is the last element it can't send anything so it should automatically go to the next phase 
                        step = (step+1);
                    }
                    
                    //odd step -> even chares send their values to left neighbor 
                    if (thisIndex > 0) {
                        CkFuture future2 = CkCreateFuture();
                        thisProxy[thisIndex - 1].receiveValue(index, myval, future2);
                        MsgData* msg2 = (MsgData*)CkWaitFuture(future2);
                        myval = msg2->value; 
                        step = (step+1);

                        // delete future2; 
                        // delete msg2; 
                    } else { //this is the last element it can't send anything so it should automatically go to the next phase 
                        step = (step+1);
                    }
                    
                }
                //if we have an odd number of elements we end with an extra even step 
                if (numElements % 2 != 0) {
                    if (thisIndex + 1 < numElements) {
                        CkFuture future = CkCreateFuture();
                        thisProxy[thisIndex + 1].receiveValue(index, myval, future);
                        MsgData* msg = (MsgData*)CkWaitFuture(future);

                        myval = msg->value; 
                        step = (step+1);
                        
                    } else { //this is the last element it can't send anything so it should automatically go to the next phase 
                        step = (step+1);
                    }
                }
                mainProxy.done();
            } 
        }

        void receiveValue(int idx, double value, CkFuture future) {
            //CkPrintf("[chare %d: phase: %d, value: %f] Received message from %d with value: %f\n", thisIndex, step, myval, idx, value);
            assert(thisIndex % 2 == 1);

            bool isFromLeft = (idx < thisIndex);
            bool correctStep = (isFromLeft && step % 2 == 0) || (!isFromLeft && step % 2== 1);

            if (correctStep) {
                processMessage(idx, value, future);
                checkBuffer();
            } else {
                BufferedMessage bufferd_msg = {idx, value, future}; 
                //CkPrintf("[chare %d] Buffering message from %d with value: %f. Current phase: %d. Current value: %f\n", thisIndex, idx, value, step, myval);
                buffer.push_back(bufferd_msg);
            }
        }

        void checkBuffer() {
            for (int i = 0; i < buffer.size(); i++) {
                BufferedMessage bufferd_msg = buffer[i]; 
                processMessage(bufferd_msg.idx, bufferd_msg.value, bufferd_msg.future);
            }
            buffer.clear();
        }

        void processMessage(int idx, double value, CkFuture future) {
            MsgData* msg = new MsgData();
            msg->index = index;

            if ((idx < thisIndex && myval < value) || (idx > thisIndex && myval > value)) {
                // Swap values
                double temp = myval;
                myval = value;
                msg->value = temp;
            } else {
                msg->value = value;
            }

            // Send the response back via the future
            if (thisIndex == (numElements - 1)) {
                step = step + 2; 
            } else {
                step = (step + 1); 
            }
            CkSendToFuture(future, msg);
        }

        void print_startmynum() {
            CkPrintf("start-> index: %d value: %f\n", thisIndex, myval);
        }

        void print_endmynum() {
            CkPrintf("end-> index: %d value: %f\n", thisIndex, myval);
            CkCallback cb(CkReductionTarget(Main, secondDone), mainProxy);
            contribute(0, NULL, CkReduction::nop, cb);
        }
};

#include "oddeven.def.h"