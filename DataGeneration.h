#ifndef UNTITLED_DATAGENERATION_H
#define UNTITLED_DATAGENERATION_H
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;

class DataGenerator {
public:
    //Generates a vector with random ints
    static vector<int> generateRandom(int size, int min = 0, int max = 1000000) {
        vector<int> data(size);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(min, max);
        for (int& val : data){
            val = dis(gen);
        }
        return data;
    }
    //presorted vector
    static vector<int> generateSorted(int size) {
        vector<int> data(size);
        for (int i = 0; i < size; ++i){ 
          data[i] = i;
        }
        return data;
    }
    //reverse vector
    static vector<int> generateReverseSorted(int size) {
        vector<int> data(size);
        for (int i = 0; i < size; ++i){
          data[i] = size - i;
        }
        return data;
    }
    //vector with duplicates
    static vector<int> generateDuplicates(int size) {
        return generateRandom(size, 0, 10);
    }
};
#endif //UNTITLED_DATAGENERATION_H
