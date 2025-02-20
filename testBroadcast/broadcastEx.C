#include "broadcast_example.decl.h"
CProxy_Main mainProxy;

// Worker chare that will receive the broadcast message
class Worker : public CBase_Worker {
public:
    Worker() {}

    // Entry method that receives the broadcast message
    void receiveBroadcast(int data) {
        CkPrintf("Worker %d received broadcast message: %d\n", thisIndex, data);
        mainProxy.done();
    }
};

// Main chare that creates the chare array and broadcasts a message
class Main : public CBase_Main {
private: 
    int numWorkers;
    int workersReceived;
public:
    Main(CkArgMsg* msg) {
        // Determine the number of worker chares
        mainProxy = thisProxy;  

        numWorkers = 4;
        workersReceived = 0; 
        // Create a 1D chare array of Worker chares
        CProxy_Worker workers = CProxy_Worker::ckNew(numWorkers);

        // Message to broadcast
        int message = 42;

        // Use broadcast to send the message to all Worker chares
        workers.receiveBroadcast(message);
    }

    void done() {
        workersReceived++; 
        if (workersReceived == numWorkers) {
            CkPrintf("All workers received the broadcast message\n");
            CkExit();    
        }
    }
};

#include "broadcast_example.def.h"

