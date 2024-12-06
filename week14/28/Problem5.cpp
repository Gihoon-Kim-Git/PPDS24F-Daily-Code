#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();

        for (int target = n; target > 0; --target) {
            int index = find(arr, target);

            if (index != target - 1) {
                if (index != 0) {
                    result.push_back(index + 1);
                    flip(arr, index + 1);
                }
                result.push_back(target);
                flip(arr, target);
            }
        }

        return result;
    }

    int find(vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == target) return i;
        }
        return -1;
    }

    void flip(vector<int>& arr, int k) {
        int left = 0, right = k - 1;
        while (left < right) {
            swap(arr[left], arr[right]);
            ++left;
            --right;
        }
    }
};