#include "kmeans.decl.h"
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib> 

CProxy_Main mainProxy; 
CProxy_Points pointsArray; 
int numElements; 
int numCentroids; 
int numChares; 
double threshold; 

class Main : public CBase_Main {
    private: 
        //number of iterations of the algorithm 
        int iterations; 
        int totalChangedCount; 

        //centroid positions themselves 
        double* centroids; 

        //represents the number of points that are assigned to each centroid
        int* counts; 

        //represents the sum of the points that are assigned to each centroid where you have [firstcentroid sum x, first centroid sum y, second centroid sum x, second centroid sum y, ...]
        double* sums; 

    public: 
        Main(CkArgMsg* m) {
            srand(time(NULL));
            
            //command line parsing
            if (m->argc != 4 && m->argc != 1) {
                CkPrintf("%s: expecting 3 arguments in the form of integers or no arguments(default values will be used in this case)\n", m->argv[0]);
                CkExit();
            }
            numElements = 1000; 
            numCentroids = 5; 
            numChares = 10; 
            threshold = 0.001;

            if (m->argc > 1) {
                numElements = atoi(m->argv[1]);
            }
            if (m->argc > 2) {
                numCentroids = atoi(m->argv[2]);
            }
            if (m->argc > 3) {
                numChares = atoi(m->argv[3]);
            }
            delete m; 

            //other initializations
            mainProxy = thisProxy;
            iterations = 0; 
            
            counts = new int[numCentroids];
            sums = new double[numCentroids * 2];

            //generate k random points as initial guess ofr centroids of the k clusters 
            centroids = new double[numCentroids * 2];
            for (int i = 0; i < numCentroids; i++) {
                centroids[2 * i] = static_cast<double>(rand()) / RAND_MAX;
                centroids[2 * i + 1] = static_cast<double>(rand()) / RAND_MAX;
            }

            //print out initial values of the centroids 
            CkPrintf("Initial centroids:\n");
            for (int i = 0; i < numCentroids; i++) {
                CkPrintf("Centroid %d: (%f, %f)\n", i, centroids[2*i], centroids[2*i + 1]);
            }


            pointsArray = CProxy_Points::ckNew(numChares);
            pointsArray.Assign(centroids);
        }

        void UpdateData(double newdata[3 * numCentroids + 1]) {
            for (int i = 0; i < numCentroids; i++) {
                sums[2 * i] = newdata[3 * i];
                sums[2 * i + 1] = newdata[3 * i + 1];
                counts[i] = static_cast<int>(newdata[3 * i + 2]);
            }
            totalChangedCount = static_cast<int>(newdata[3 * numCentroids]);
            UpdateCentroids();
        }


        void UpdateCentroids() {
            iterations++;
            if (totalChangedCount == 0) {
                // Output final centroids
                CkPrintf("K-means converged in %d iterations.\n", iterations);
                for (int i = 0; i < numCentroids; ++i) {
                    CkPrintf("Centroid %d: (%f, %f)\n", i, centroids[2 * i], centroids[2 * i + 1]);
                }
                CkExit();
            }

            // Update centroids and check for convergence
            for (int i = 0; i < numCentroids; ++i) {
                if (counts[i] > 0) {
                    double newX = sums[2 * i] / static_cast<int>(counts[i]);
                    double newY = sums[2 * i + 1] / static_cast<int>(counts[i]);

                    double deltaX = std::abs(newX - centroids[2 * i]);
                    double deltaY = std::abs(newY - centroids[2 * i + 1]);

                    // Update centroids to the new values 
                    centroids[2 * i] = newX;
                    centroids[2 * i + 1] = newY;
                } else {
                    // Handle empty clusters by re-initializing centroid
                    centroids[2 * i] = static_cast<double>(rand()) / RAND_MAX;
                    centroids[2 * i + 1] = static_cast<double>(rand()) / RAND_MAX;
                }

                // Reset counts and sums for next iteration
                counts[i] = 0; 
                sums[2 * i] = 0.0;
                sums[2 * i + 1] = 0.0;
            }

            pointsArray.Assign(centroids);
        }
};

class Points: public CBase_Points {
    private: 
        std::vector<std::pair<double, double>> localpoints; //represents the points that this chare is responsible for

        //our double array represents is indreictly in the form of [(x, y, count), ...]
        double* localData; //data that will be contributed and eventuyally sent to the main chare

        int* PointCentroidAssignments; //represents the centroid that each point is assigned to
    public: 
        Points() {
            //for now we will assume things will divide evenly 
            int num_points_in_chare = numElements / numChares;
            for (int i = 0; i < num_points_in_chare; i++) {
                double x = static_cast<double>(rand()) / RAND_MAX;
                double y = static_cast<double>(rand()) / RAND_MAX;
                localpoints.push_back(std::make_pair(x, y));
            }

            localData = new double[3 * numCentroids + 1]; //the + 1 is for the number of points changed 

            PointCentroidAssignments = new int[localpoints.size()];
            for (size_t i = 0; i < localpoints.size(); i++) {
                PointCentroidAssignments[i] = -1; 
            }
        }

        void Assign(double centroids[2 * numCentroids]) {
            
            int changedPoints = 0; 

            //might need to reset?
            for (int i = 0; i < numCentroids; i++) {
                localData[3 * i + 2] = 0.0; 
                localData[3 * i] = 0.0; 
                localData[3 * i + 1] = 0.0; 
            }
            localData[3 * numCentroids] = 0.0;

            //assign each point to the cloest centroid 
            for (size_t i = 0; i < localpoints.size(); i++) {
                double minDist = std::numeric_limits<double>::max();
                int index = -1; 
                for (int j = 0; j < numCentroids; j++) {
                    double dx = localpoints[i].first - centroids[2 * j];
                    double dy = localpoints[i].second - centroids[2 * j + 1];
                    double dist = dx * dx + dy * dy;
                    if (dist < minDist) {
                        minDist = dist; 
                        index = j; 
                    }
                }
                
                if (PointCentroidAssignments[i] != index) {
                    changedPoints++;
                    PointCentroidAssignments[i] = index;
                }
                

                localData[3 * index + 2]++;
                localData[3 * index] += localpoints[i].first;
                localData[3 * index + 1] += localpoints[i].second;

            }
            localData[3 * numCentroids] = static_cast<double>(changedPoints); 
            CkCallback cb_sums(CkReductionTarget(Main, UpdateData), mainProxy); 
            contribute(sizeof(double) * (3 * numCentroids + 1), localData, CkReduction::sum_double, cb_sums);
        }
};



#include "kmeans.def.h"