/*
Quick Sort is a Divide and Conquer algorithm. It picks an element as a pivot and
partitions the given array around the picked pivot. Given an array arr[], its
starting position is low (the index of the array) and its ending position is
high(the index of the array).

Note: The low and high are inclusive.

Implement the partition() and quickSort() functions to sort the array.
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

// Or use parray e.g. parray 5 arr
string ArrToString(int arr[], int n) {
  ostringstream ss;
  for (int i = 0; i < n; ++i) {
    ss << arr[i];
    if (i < n - 1) ss << " ";
  }
  return ss.str();
}

/**
 * @brief With the first element as pivot,
 * partition in-place and return the partition index
 *
 * @param arr
 * @param low Initially, low < high
 * @param high
 * @return int Index of split
 */
int Partition(int arr[], int low, int high) {
  int pv = arr[low];
  int i = low + 1, j = high;
  while (i <= j) {
    while (arr[i] < pv) ++i;
    while (arr[j] > pv) --j;
    if (i >= j) {              // crosses each other
      swap(arr[low], arr[j]);  // swap with pivot
      return j;
    } else {
      swap(arr[i], arr[j]);
    }
  }
  return i;
}

void QuickSort(int arr[], int low, int high) {
  if (high <= low) {  // single
    return;
  }
  int idx = Partition(arr, low, high);
  QuickSort(arr, low, idx - 1);
  QuickSort(arr, idx + 1, high);
}

int main() {
  int arr[] = {4, 1, 3, 9, 7};
  QuickSort(arr, 0, 4);
  assert(ArrToString(arr, 5) == "1 3 4 7 9");
  return 0;
}
