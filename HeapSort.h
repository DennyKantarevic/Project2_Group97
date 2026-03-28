#pragma once
#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <vector>

using namespace std;

void swapVal(vector<int>& v, int i, int j);
void heapify(vector<int>& v, int n, int i);
void heapSort(vector<int>& v);

#endif