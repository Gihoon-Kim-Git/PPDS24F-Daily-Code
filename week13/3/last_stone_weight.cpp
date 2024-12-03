// You are given an array of integers `stones` where stones[i] is the weight of the ith stone.
//
// We are playing a game with the stones. On each turn, we choose the heaviest two stones
// and smash them together. Suppose the heaviest two stones have weights x and y with x <= y.
// The result of this smash is:
//
// - If x == y, both stones are destroyed.
// - If x != y, the stone of weight x is destroyed, and the stone of weight y has a new weight y - x.
//
// At the end of the game, there is at most one stone left.
//
// Return the weight of the last remaining stone. If there are no stones left, return 0.
//
// Example 1:
// Input: stones = [2,7,4,1,8,1]
// Output: 1
// Explanation:
// Combine 7 and 8 to get 1, array becomes [2,4,1,1,1]
// Combine 2 and 4 to get 2, array becomes [2,1,1,1]
// Combine 2 and 1 to get 1, array becomes [1,1,1]
// Combine 1 and 1 to get 0, array becomes [1]
// Return the last remaining stone: 1
//
// Example 2:
// Input: stones = [1]
// Output: 1
//
// Constraints:
// - 1 <= stones.length <= 30
// - 1 <= stones[i] <= 1000


#include <vector>
#include <iostream>

using namespace std; // std::vector

class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void selection_sort_descending(vector<int>& arr) {
        // selection sort in descending order
        int n = arr.size();
        // find maximum element in remaining unsorted part of array
        for (int i = 0; i < n; i++) {
            int max_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[max_idx]) {
                    max_idx = j;
                }
            }
            // swap maximum element with current element
            swap(arr[i], arr[max_idx]);
        }
    }

    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            selection_sort_descending(stones);
            int max_first = stones[0];
            int max_second = stones[1];
            // replacing is not necessary
            // just can remove the stones by sorted order every time

            // remove the two heaviest stones
            stones.erase(stones.begin());
            stones.erase(stones.begin());

            // stone of weight x is destroyed, and stone of weight y has new weight y-x
            if (max_first != max_second) {
                stones.push_back(max_first - max_second);
            }
        }

        // at most one stone left after while loop
        // return stones.empty() ? 0 : stones[0];
        if (stones.empty()) {
            return 0;
        } else {
            return stones[0];
        }
    }
};

// Example usage
int main() {
    std::vector<int> stones = {2, 7, 4, 1, 8, 1};
    Solution solution; // Create an instance of the Solution class
    int result = solution.lastStoneWeight(stones);
    std::cout << "Last stone weight: " << result << std::endl; // 1
    return 0;
}