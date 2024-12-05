#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        helper(result, arr);
        return result;
    }
    
    void helper(vector<int>& result, vector<int>& arr) {
        if (arr.size() == 1) return;
        
        // Find the index of the maximum element
        int maxIndex = max_element(arr.begin(), arr.end()) - arr.begin();
        
        // If the maximum element is not in the correct position
        if (maxIndex != arr.size() - 1) {
            if (maxIndex != 0) {
                // Flip the part of the array that contains the maximum element to move it to the front
                result.push_back(maxIndex + 1);
                reverse(arr.begin(), arr.begin() + maxIndex + 1);
            }
            
            // Flip the entire array to move the maximum element to its correct position
            result.push_back(arr.size());
            reverse(arr.begin(), arr.end());
        }
        
        // Recursively call helper with the reduced array size (excluding the last element)
        arr.pop_back();
        helper(result, arr);
    }
};

int main() {
    Solution solution;
    vector<int> arr = {3, 2, 4, 1};
    
    vector<int> result = solution.pancakeSort(arr);
    
    // Print the result
    for (int flip : result) {
        cout << flip << " ";
    }
    cout << endl;

    return 0;
}
