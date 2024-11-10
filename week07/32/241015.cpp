#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j=low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);

    return i+1;
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

void print_array(vector<int>& arr) {
    for (int i=0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "원래 배열: ";
    print_array(arr);
    cout << endl;

    quick_sort(arr, 0, arr.size()-1);

    cout << "정렬된 배열: ";
    print_array(arr);
}