/*Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [1,3,5]
Output: 1
Example 2:

Input: nums = [2,2,2,0,1]
Output: 0
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums is sorted and rotated between 1 and n times.*/

/*풀이
    1. binary search 틀을 가져오되.... 조건문 수정
        2. if nums[mid] > nums[right] ---> 오른쪽탐색. mid 제외. 최솟값이 아니니까 --> left = mid+1
            else if nums[mid]  < nums[right] --> 왼쪽 탐색.  mid 제외하면 안됨. 최솟값일수도 있으니까 -- > right = mid
            else #nums[mid] == nums[right] 일때... --> 어느쪽을 탐색할지 알기 어렵다. 따라서 같지 않을때까지 right를 바꿔주자. ---> right = right-1
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findMin(vector<int>& nums){
        int left = 0;
        int right = nums.size()-1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) left = mid+1;
            else if (nums[mid] < nums[right]) right = mid;
            else right--;  // nums[mid] == nums[right]일 때..
        }
        // left == right일때가 답.
        return nums[right];

    }
};


#include <algorithm>
int findMin(vector<int>& nums){
    return *min_element(begin(nums), end(nums));
}
