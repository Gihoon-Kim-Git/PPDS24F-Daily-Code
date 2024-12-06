#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> answer;
        int end = arr.size() - 1;
        while (end > 0) {
            int a = 0, b = 0;
            for (int i=0; i<end+1; i++) {
                if (a < arr[i]) {
                    a = arr[i];
                    b = i;
                }
            }
            answer.push_back(b+1);
            reverse(arr.begin(), arr.begin() + b + 1);
            answer.push_back(end+1);
            reverse(arr.begin(), arr.begin() + end + 1);
            end--;
        }
        return answer;
    }
};

int main() {
    Solution result;
    vector<int> arr1 = {3,2,4,1};
    vector<int> answer1 = result.pancakeSort(arr1);
    for (auto i: answer1) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> arr2 = {1,2,3};
    vector<int> answer2 = result.pancakeSort(arr2);
    for (auto j: answer2) {
        cout << j << " ";
    }
    cout << endl;
    return 0;
}