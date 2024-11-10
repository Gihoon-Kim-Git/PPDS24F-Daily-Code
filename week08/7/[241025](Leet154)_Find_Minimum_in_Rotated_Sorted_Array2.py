"""Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

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
nums is sorted and rotated between 1 and n times."""

"""풀이: 만약, nums[mid] == nums[right]인 경우, r을 r-1해보자.
"""

def findMin(self, nums) -> int:
    left, right = 0, len(nums)-1
    
    while left < right :
        mid = (left + right) // 2
        if nums[mid] < nums[right] : #탐색범위를 left ~ mid (왼쪽절반으로 수정. mid 포함)
            right = mid
        elif nums[mid] > nums[right] : #--> 오른쪽 절반을 봐야 함. mid 제외가능. mid가 최소값이 아니므로
            left = mid+1
        else: #nums[mid] == nums[right]   <---- 이 부분만 처리해주면 됨!
            right -= 1
    # left == right일 때 최솟값임.
    return nums[right]



#unique elements를 다루듯이 풀었을 때 반례) [1,3,3], [3,3,1,3]

##---[Leet153] Fine Minimum in Roatated Sorted Array : when all elements in nums are 'unique'----------------------------------------
"""풀이 : left, mid, right를 관리하는데, mid, right를 비교햇을 때 더 작은 element쪽의 구역으로 search 범위를 좁혀간다."""

"""hint
    All the elements to the left of inflection point > first element of the array.
    All the elements to the right of inflection point < first element of the array."""

def findMin(nums):
    left, right = 0, len(nums)-1
    
    while left < right :
        mid = (left + right) // 2
        if nums[mid] <= nums[right] : #탐색범위를 left ~ mid (왼쪽절반으로 수정. mid 포함)
            right = mid
        else : # nums[mid] > nums[right]  --> 오른쪽 절반을 봐야 함. mid 제외가능. mid가 최소값이 아니므로
            left = mid+1
    # left == right일 때 최솟값임.
    return nums[right]
    
            