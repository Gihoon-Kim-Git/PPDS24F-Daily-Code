#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr, int piv, int low, int high) {
   piv = arr[high];
   int i = (low - 1);

   for (int j = low; j < high; j++) {
    if (arr[j] < piv) {
        i++;
        swap(arr[i], arr[j]);
    }
   }
   swap(arr[i+1], arr[high]);
   return (i+1);
}

void quickSort(vector<int> &arr, int N, int low, int high) {
    if (low < high) {
        int pi = partition(arr, N, low, high);

        quickSort(arr, N, low, pi -1);
        quickSort(arr, N, pi+1, high);
    }
}

int main(void) {
    int N1 = 5;
    int N2 = 9;
    vector<int> arr1; 
    vector<int> arr2; 
    
    arr1.push_back(4);
    arr1.push_back(1);
    arr1.push_back(3);
    arr1.push_back(9);
    arr1.push_back(7);

    arr2.push_back(2);
    arr2.push_back(1);
    arr2.push_back(6);
    arr2.push_back(10);
    arr2.push_back(4);
    arr2.push_back(1);
    arr2.push_back(3);
    arr2.push_back(9);
    arr2.push_back(7);

    quickSort(arr1, N1, 0, arr1.size()-1);
    quickSort(arr2, N2, 0, arr2.size()-1);

    // print
    for (int i: arr1) {
        cout << i << " ";
    }
    cout << '\n';

    for (int i: arr2) {
        cout << i << " ";
    }
    return 0;
}
