#include <iostream>
#include <vector>

using namespace std;

// For Swapping Values
void swapVal(vector<int>& v, int i, int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

// Heapifying
void heapify(vector<int>& v, int n, int i) {
	int greatest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && v[left] > v[greatest]) {
		greatest = left;
	}
	if (right < n && v[right] > v[greatest]) {
		greatest = right;
	}

	// Swap if needed
	if (greatest != i) {
		swapVal(v, i, greatest);
		heapify(v, n, greatest);
	}
}

// The Actual Sorting
void heapSort(vector<int>& v) {
	// Length of Vector v
	int len = v.size();
	
	for (int i = len / 2 - 1; i >= 0; i--) {
		heapify(v, len, i);
	}

	for (int i = len - 1; i > 0; i--) {
		swapVal(v, 0, i);
		heapify(v, i, 0);
	}
}