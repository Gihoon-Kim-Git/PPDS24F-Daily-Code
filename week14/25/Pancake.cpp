#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        for (int size = (int)arr.size(); size > 1; --size) {
            // Find the position of the largest element not yet placed
            int max_idx = 0;
            for (int i = 1; i < size; ++i) {
                if (arr[i] > arr[max_idx]) {
                    max_idx = i;
                }
            }

            // If the largest element is already in correct position, just continue
            if (max_idx == size - 1) {
                continue;
            }
            
            // If the largest element is not at the front, we need to flip it to the front first
            if (max_idx > 0) {
                reverse(arr.begin(), arr.begin() + max_idx + 1);
                res.push_back(max_idx + 1);
            }

            // Now flip it to its correct position at the end (size)
            reverse(arr.begin(), arr.begin() + size);
            res.push_back(size);
        }
        return res;
    }
};