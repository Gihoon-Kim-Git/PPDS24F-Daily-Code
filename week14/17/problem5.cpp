// Given an array of integers arr, sort the array by performing a series of pancake flips.

// In one pancake flip we do the following steps:

// Choose an integer k where 1 <= k <= arr.length.
// Reverse the sub-array arr[0...k-1] (0-indexed).
// For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.

// Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.


#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {

        // max 찾음 -> flip(idx) -> filp(전체) -> arr[:-1] 로 다시 반복
        vector<int> ans;

        while (arr.size() > 1){
            
            int max_idx = 0;
            int max_val = arr[0];

            for (int i=1; i<arr.size(); i++){
                if (arr[i] > max_val){
                    max_val = arr[i];
                    max_idx = i;
                }
            }

            ans.push_back(max_idx+1);
            flip(arr, max_idx);

            ans.push_back(arr.size());
            flip(arr, arr.size()-1);

            arr.pop_back();
        }

        return ans;
    }

    void flip(vector<int>& arr, int idx){
        int left = 0;
        int right = idx;

        while (left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

};