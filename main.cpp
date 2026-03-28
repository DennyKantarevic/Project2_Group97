#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <fstream>
#include "DataGeneration.h"
#include "MergeSort.h"
#include "HeapSort.h"
using namespace std;

void algoTest(vector<int> dataset, string testName, int mode){
  //implementation needed to run test (get the time) based on different algorithms. Uses parameters dataset testName and mode to pick between merge or heap sort.
  using namespace chrono;

  //merge sort
  if (mode == 1) {
    vector<int> dataCopy = dataset;

    auto start = high_resolution_clock::now();
    mergeSort(dataCopy, 0, dataCopy.size() - 1);
    auto end = high_resolution_clock::now();

    double elapsed = chrono::duration<double>(end-start).count();

    cout << fixed << setprecision(3);
    cout << "\nRunning Merge Sort...\n";
    cout << "Merge Sort Runtime: " << elapsed << " seconds\n";
  }

  // Heap Sort
  if (mode == 2) {
    vector<int> dataCopy = dataset;

    auto start = high_resolution_clock::now();
    heapSort(dataCopy);
    auto end = high_resolution_clock::now();

    double elapsed = chrono::duration<double>(end-start).count();

    cout << fixed << setprecision(3);
    cout << "\nRunning Heap Sort...\n";
    cout << "Heap Sort Runtime: " << elapsed << " seconds\n";
  }

  if (mode == 3) {
    vector<int> dataCopy = dataset;

    auto start_merge = high_resolution_clock::now();
    mergeSort(dataCopy, 0, dataCopy.size() - 1);
    auto end_merge = high_resolution_clock::now();

    double elapsed_merge = chrono::duration<double>(end_merge-start_merge).count();

    cout << fixed << setprecision(3);
    cout << "\nRunning Merge Sort...\n";
    cout << "Merge Sort Runtime: " << elapsed_merge << " seconds\n";

    auto start_heap = high_resolution_clock::now();
    heapSort(dataCopy);
    auto end_heap = high_resolution_clock::now();

    double elapsed_heap = chrono::duration<double>(end_heap-start_heap).count();

    cout << fixed << setprecision(3);
    cout << "\nRunning Heap Sort...\n";
    cout << "Heap Sort Runtime: " << elapsed_heap << " seconds\n\n";

    if (elapsed_merge > elapsed_heap) {
      double difference = elapsed_merge - elapsed_heap;
      cout << setprecision(5);
      cout << "Heap Sort performed faster on this dataset by " << difference << " seconds." << endl;
    }
    else {
      double difference = elapsed_heap - elapsed_merge;
      cout << setprecision(5);
      cout << "Merge Sort performed faster on this dataset by " << difference << " seconds." << endl;
    }
  }

}

int main(){
  int size = 100000;
  int dataChoice, algoChoice;

  cout << "--- SortBench Performance Tool ---\n";
  cout << "1. Random Dataset\n";
  cout << "2. Sorted Dataset\n";
  cout << "3. Reverse Sorted Dataset\n";
  cout << "4. Duplicates Dataset\n";
  cout << "Selection: ";
  cin >> dataChoice;

  cout << "\nChoose Algorithm:\n";
  cout << "1. Merge Sort\n";
  cout << "2. Heap Sort\n";
  cout << "Selection: ";
  cin >> algoChoice;

  vector<int> dataset;
  string name;
  
  // Generate based on selection
  if (dataChoice == 1) {dataset = DataGenerator::generateRandom(size); name = "Random";}
  else if (dataChoice == 2) {dataset = DataGenerator::generateSorted(size); name = "Sorted";}
  else if (dataChoice == 3) {dataset = DataGenerator::generateReverseSorted(size); name = "Reverse";}
  else if (dataChoice == 4) {dataset = DataGenerator::generateDuplicates(size); name = "Duplicates";}
  else {
    cout << "Invalid Dataset Selection." << endl;
    return 0;
  }
  algoTest(dataset, name, algoChoice);
  return 0;
}
