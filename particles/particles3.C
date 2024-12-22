#include "particles.decl.h"
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <random>
#include <stdio.h>
#include <stdio.h>
#include <utility>
#include <iostream>
#include <assert.h>

CProxy_Main mainProxy; 
CProxy_coordchare coords_array; 

int xmin; 
int xmax; 
int ymin;
int ymax; 
int iterations; 

int particlesPerCell; //read from command line, represents number of particles each chare should have 
int k; //read from command line, the simulation will create a 2 dimensional array of chares of size k x k. Each chare will have a bounding box of its own size 100.0/k

class MsgData : public CMessage_MsgData {
    public: 
        int isCount; //-1 if it is a particle message, otherwise it is the number of particles that should be received 
        int x; 
        int y; 

        int senderx; 
        int sendery; 
};

class Main : public CBase_Main {
    private:
        int charesreceived; 
    public: 
        Main(CkArgMsg* msg) {
            if (msg->argc != 3) {
                CkPrintf("Usage: ./charmrun +p<n> ./particles N K\n"); 
                CkExit();
            }

            particlesPerCell = atoi(msg->argv[1]);
            k = atoi(msg->argv[2]);
            mainProxy = thisProxy; 

            xmin = 0; 
            xmax = 100; 
            ymin = 0; 
            ymax = 100; 

            delete msg; 

            iterations = 100; 
            charesreceived = 0; 

            CkPrintf("Starting simulation\n");
            coords_array = CProxy_coordchare::ckNew(k, k);
            coords_array.startSimulation();
        }

        void maxReductionDone(int max) {
            CkPrintf("Max Number of particles that a chare has is: %d \n", max);
        }

        void sumReductionDone(int sum) {
            CkPrintf("Total particles in the simulation %d \n", sum);
        }

        void done() {
            charesreceived++; 
            //CkPrintf("Chares received %d\n", charesreceived);
            if (charesreceived == (k * k)) {
                CkPrintf("Simulation done\n");
                CkExit();
            }
        }
};


class coordchare: public CBase_coordchare {
    private: 
        struct Particle {
            double x; 
            double y; 
        };

        struct messageCounter {
            int need; 
            int received; 
        };

        int xstart; 
        int xend; 
        int ystart; 
        int yend; 
        int charesNeeded; //need to hear from charesNeeded chares before proceeding to the next iteration

        int charesReceived; //number of chares that have completely sent their particles to this chare
        std::vector<Particle> particles;
        std::map<std::pair<int, int>, std::vector<Particle>> neighborParticles; //map of particles to send 
        std::map<std::pair<int, int>, messageCounter> messageCounters; //map of message counters to keep track of how many messages have been received from each neighbor

        int iteration; 

        void resetForNextIteration() {
            charesReceived = 0; 
            for (auto &entry : messageCounters) {
                entry.second.need = -1; 
                entry.second.received = 0; 
            }
            for (auto &kv : neighborParticles) {
                kv.second.clear();
            }
        }
    public: 
        coordchare() {
            srand48(time(NULL) + thisIndex.x + thisIndex.y);

            xstart = thisIndex.x * (xmax - xmin) / k;
            xend = (thisIndex.x + 1) * (xmax - xmin) / k;

            ystart = thisIndex.y * (ymax - ymin) / k;
            yend = (thisIndex.y + 1) * (ymax - ymin) / k;

            for (int i = 0; i < particlesPerCell; i++) {
                Particle p; 
                p.x = xstart + static_cast<double>(rand()) / RAND_MAX * (xend - xstart);
                p.y = ystart + static_cast<double>(rand()) / RAND_MAX * (yend - ystart);
                particles.push_back(p);
            }
            
            //finds the number of messages a chare should receive before going on to the next iteration 
            charesNeeded = 4; 
            if (thisIndex.x == 0 || thisIndex.x == k - 1) {
                charesNeeded--;
            }
            if (thisIndex.y == 0 || thisIndex.y == k - 1) {
                charesNeeded--;
            }

            // Initialize messageCounters and neighborParticles based on neighbors
            if (thisIndex.x != 0) {
                messageCounters[std::make_pair(thisIndex.x - 1, thisIndex.y)] = { -1, 0 };
                neighborParticles[std::make_pair(thisIndex.x - 1, thisIndex.y)] = {};
            }
            if (thisIndex.x != k - 1) {
                messageCounters[std::make_pair(thisIndex.x + 1, thisIndex.y)] = { -1, 0 };
                neighborParticles[std::make_pair(thisIndex.x + 1, thisIndex.y)] = {};
            }
            if (thisIndex.y != 0) {
                messageCounters[std::make_pair(thisIndex.x, thisIndex.y - 1)] = { -1, 0 };
                neighborParticles[std::make_pair(thisIndex.x, thisIndex.y - 1)] = {};
            }
            if (thisIndex.y != k - 1) {
                messageCounters[std::make_pair(thisIndex.x, thisIndex.y + 1)] = { -1, 0 };
                neighborParticles[std::make_pair(thisIndex.x, thisIndex.y + 1)] = {};
            }

            charesReceived = 0;
            iteration = 0; 
            assert(charesNeeded == (int)messageCounters.size());
        }

        coordchare(CkMigrateMessage* msg) {}

        void startSimulation() {
            resetForNextIteration();

            CkPrintf("Chare (%d, %d) is starting iteration %d\n", thisIndex.x, thisIndex.y, iteration);
            if (charesNeeded == 0) {
                iterationDone();
            }

            std::vector<int> particlesToErase; 
            for (int i = 0; i < (int)particles.size(); i++) {
                Particle p = particles[i];
                bool movex = rand() % 2;
                double amounttomove = (static_cast<double>(rand()) / RAND_MAX - 0.5) * 0.1; 
                if (movex && p.x + amounttomove < xmax && p.x + amounttomove > xmin) {
                    p.x += amounttomove;
                    if (p.x < xstart) {
                        neighborParticles[std::make_pair(thisIndex.x - 1, thisIndex.y)].push_back(p);
                        particlesToErase.push_back(i);
                    } else if (p.x > xend) {
                        neighborParticles[std::make_pair(thisIndex.x + 1, thisIndex.y)].push_back(p);
                        particlesToErase.push_back(i);
                    }
                } else if (!movex && p.y + amounttomove < ymax && p.y + amounttomove > ymin) {
                    p.y += amounttomove;
                    if (p.y < ystart) {
                        neighborParticles[std::make_pair(thisIndex.x, thisIndex.y - 1)].push_back(p);
                        particlesToErase.push_back(i);
                    } else if (p.y > yend) {
                        neighborParticles[std::make_pair(thisIndex.x, thisIndex.y + 1)].push_back(p);
                        particlesToErase.push_back(i);
                    }
                }
            }
            // Erase moved particles
            // Careful: erase from end to start to avoid invalidating indices
            std::sort(particlesToErase.begin(), particlesToErase.end(), std::greater<int>());
            for (auto idx : particlesToErase) {
                particles.erase(particles.begin() + idx);
            }
            
            thisProxy(thisIndex.x, thisIndex.y).notifyAndSendToNeighbors();
        }

        void notifyAndSendToNeighbors() {
            //CkPrintf("Chare (%d, %d) is calling notifyAndSendToNeighbors\n", thisIndex.x, thisIndex.y);
            //assert map length is at most 4 
            assert(neighborParticles.size() <= 4);
            for (auto &mc : messageCounters) {
                std::pair<int,int> neighborIndex = mc.first;
                // Send size message
                int count = (int)neighborParticles[neighborIndex].size();
                CkPrintf("Chare (%d, %d) sending %d particles to (%d, %d)\n", thisIndex.x, thisIndex.y, count, neighborIndex.first, neighborIndex.second);

                MsgData* sizeMsg = new MsgData();
                sizeMsg->isCount = count;
                sizeMsg->senderx = thisIndex.x;
                sizeMsg->sendery = thisIndex.y;
                thisProxy(neighborIndex.first, neighborIndex.second).receiveParticle(sizeMsg);

                // Send actual particles
                for (auto &p : neighborParticles[neighborIndex]) {
                    MsgData* particleMsg = new MsgData();
                    particleMsg->isCount = -1;
                    particleMsg->x = p.x;
                    particleMsg->y = p.y;
                    particleMsg->senderx = thisIndex.x;
                    particleMsg->sendery = thisIndex.y;
                    thisProxy(neighborIndex.first, neighborIndex.second).receiveParticle(particleMsg);
                }
            }
        }

        void receiveParticle(MsgData* msg) {
            if (iteration == iterations) {
                delete msg; 
                return; 
            }

            //CkPrintf("Chare (%d, %d) received a particle from (%d, %d)\n", thisIndex.x, thisIndex.y, msg->senderx, msg->sendery);
            messageCounter& chare = messageCounters[std::make_pair(msg->senderx, msg->sendery)];
            if (msg->isCount >= 0) {
                //this is a size message 
                chare.need = msg->isCount;
                if (chare.received == chare.need) {
                    charesReceived++;
                    if (charesReceived == charesNeeded) {
                        thisProxy(thisIndex.x, thisIndex.y).iterationDone();
                    }
                }
            } else if (msg->isCount == -2) {
                //this is a done message 
                //delete this neighbor from the maps
                //CkPrintf("received a done message\n");

                messageCounters.erase(std::make_pair(msg->senderx, msg->sendery));
                neighborParticles.erase(std::make_pair(msg->senderx, msg->sendery));
                
                charesNeeded--;
                if (charesReceived == charesNeeded) {
                    thisProxy(thisIndex.x, thisIndex.y).iterationDone();
                }
                delete msg;
            } else {
                //add particle to it's vector of particles 
                Particle new_p; 
                new_p.x = msg->x;
                new_p.y = msg->y;
                particles.push_back(new_p);

                chare.received += 1;
                if (chare.received == chare.need) {
                    charesReceived++;
                    if (charesReceived == charesNeeded) {
                        thisProxy(thisIndex.x, thisIndex.y).iterationDone();
                    }
                }
            }
            delete msg; 
        }

        void iterationDone() {
            iteration++; 
            if (iteration % 10 == 0) {
                //contribute to reduction
                int particleCount = (int)particles.size();
                CkCallback cb_sum(CkReductionTarget(Main, sumReductionDone), mainProxy); 
                contribute(sizeof(int), &particleCount, CkReduction::sum_int, cb_sum);

                //contribute to reduction 
                CkCallback cb_max(CkReductionTarget(Main, maxReductionDone), mainProxy);
                contribute(sizeof(int), &particleCount, CkReduction::max_int, cb_max);
            } 

            //this chare hit the iteration limit
            if (iteration == iterations) {
                //CkPrintf("Chare (%d, %d) is done\n", thisIndex.x, thisIndex.y);
                mainProxy.done();
                for (auto &mc : messageCounters) {
                    std::pair<int,int> neighborIndex = mc.first;
                    MsgData* doneMsg = new MsgData();
                    doneMsg->isCount  = -2; // Use a special value to indicate "done"
                    doneMsg->senderx  = thisIndex.x;
                    doneMsg->sendery  = thisIndex.y;
                    thisProxy(neighborIndex.first, neighborIndex.second).receiveParticle(doneMsg);
                }
            } else {
                thisProxy(thisIndex.x, thisIndex.y).startSimulation();
            }
        }
};

#include "particles.def.h"