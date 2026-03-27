#include <iostream>
#include <iomanip>
#include <fstream>
#include "DataGenerator.h"
using namespace std;

void algoTest(vector<int> dataset, string testName, int mode){
  //implementation needed to run test (get the time) based on different algorithms. Uses parameters dataset testName and mode to pick between merge or heap sort.
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
