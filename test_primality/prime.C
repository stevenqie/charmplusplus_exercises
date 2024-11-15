#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <algorithm>
#include <charm++.h>
#include <vector>

#include "test_primality.decl.h"

CProxy_Origin originInstance;

class Origin : public CBase_Origin {
    private: 
        int k; //numbers to test  
        int batchsize; //batch size      
        std::vector<std::pair<uint64_t, int>> arr; //array that holds pairs which represent numbers and whether they are prime or not
        int numbersreceived; 
        double startTime; 
    public: 
        Origin(CkArgMsg* m) {
            //ensuring we get different random numbers everytime
            srand(static_cast<unsigned int>(time(NULL)));

            //command line parsing 
            if (m->argc != 3) {
                CkPrintf("%s: expecting 2 argument in the form of an integer representing numbers that you want to test and another integer representing the batch size\n", m->argv[0]);
                CkExit();
            }
            
            originInstance = thisProxy; 
            k = atoi(m->argv[1]);
            batchsize = atoi(m->argv[2]);
            numbersreceived = 0;
            arr.resize(k, {0, 0}); //init vector with k elements

            //setup
            for (size_t i = 0; i < k; i++) {
                uint32_t randomNum = static_cast<uint32_t>(rand());
                arr[i] = std::make_pair(randomNum, 0);
            }

            startTime = CkWallTimer();
            //running the program 
            for (int i = 0; i < k; i+=batchsize) {
                int arraysize = std::min(batchsize, k - i);
                //creating a new array of numbers to test
                std::vector<uint64_t> numbers;
                numbers.reserve(arraysize);
                for (size_t j = 0; j < arraysize; ++j) {
                    numbers.push_back(arr[i + j].first);
                }
                CProxy_checkPrimality primechecker = CProxy_checkPrimality::ckNew(arraysize, numbers.data(), i);
            }
        }

        void donePrime(size_t idx, int length, int result[]) {
            //updating the array with the result
            for (int i = 0; i < length; i++) {
                arr[idx + i].second = result[i]; 
            }
            numbersreceived+=length;
            //all numbers have been processed: print out results and end the program 
            if (numbersreceived == k) {
                double endTime = CkWallTimer();
                CkPrintf("Time taken in seconds: %f\n", endTime - startTime);
                //print out results 
                // for (size_t i = 0; i < k; i++) {
                //     CkPrintf("Number: %llu, is_prime: %s\n", arr[i].first, arr[i].second == 1 ? "True" : "False");
                // }
                CkExit();
            }
        }
};

class checkPrimality : public CBase_checkPrimality {
    public: 
        checkPrimality(int length, uint64_t nums[], size_t idx) {
            std::vector<int> toreturn(length); 
            for (int i = 0; i < length; i++) {
                int res = isPrime(nums[i]);
                toreturn[i] = res; 
            }
            originInstance.donePrime(idx, length, toreturn.data());
        }

        int isPrime(uint64_t number) {
            if (number <= 1) {
                return 0; 
            }
            if (number == 2) {
                return 1;
            }
            if (number % 2 == 0) {
                return 0; 
            }
            for (size_t i = 3; i * i <= number; i+=2) {
                if (number % i == 0) {
                    return 0; 
                }
            }
            return 1; 
        }
};

#include "test_primality.def.h"