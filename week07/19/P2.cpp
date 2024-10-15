#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> quickSort(vector<int> arr) {
        if (arr.size() <=1) return arr;
        vector<int> low, high;
        int pivot = arr[0];
        for (int i=1; i<arr.size(); i++) {
            if (arr[i] <= pivot) low.push_back(arr[i]);
            else high.push_back(arr[i]);
        }
        low = quickSort(low);
        high = quickSort(high);
        for (int j=0; j<low.size(); j++) arr[j] = low[j];
        arr[low.size()] = pivot;
        for (int k=0; k<high.size(); k++) arr[low.size()+k+1] = high[k];
        return arr;
    }
};

int main() {
    vector<int> arr = {2, 1, 6, 10, 4, 1, 3, 9, 7};
    Solution result;
    vector<int> answer = result.quickSort(arr);
    for (int i=0; i<answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}