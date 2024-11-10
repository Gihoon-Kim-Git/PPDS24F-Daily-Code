#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the minimum element in a rotated sorted array
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // Binary Search approach
        while (left < right) {
            int mid = left + (right - left) / 2; // Calculate mid index

            if (nums[mid] > nums[right]) {
                // Minimum must be in the right half
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                // Minimum must be in the left half
                right = mid;
            } else { // nums[mid] == nums[right]
                // Reduce the search space by one if they are equal
                right -= 1;
            }
        }

        // After the loop, left points to the minimum element
        return nums[left];
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 3, 5};
    cout << "Minimum in [1, 3, 5]: " << solution.findMin(nums1) << endl; // Output: 1

    // Example 2
    vector<int> nums2 = {2, 2, 2, 0, 1};
    cout << "Minimum in [2, 2, 2, 0, 1]: " << solution.findMin(nums2) << endl; // Output: 0

    // Additional Example
    vector<int> nums3 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum in [4, 5, 6, 7, 0, 1, 2]: " << solution.findMin(nums3) << endl; // Output: 0

    return 0;
}

/*
0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week08 (main)
$ g++ findmin_rsarr.cpp -o findmin

0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week08 (main)
$ ./findmin
Minimum in [1, 3, 5]: 1
Minimum in [2, 2, 2, 0, 1]: 0
Minimum in [4, 5, 6, 7, 0, 1, 2]: 0
*/