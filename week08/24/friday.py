from typing import List

# Find Min in Rotated Sorted Array 2
class Solution:
    def findMin(self, nums: List[int]) -> int:
        first=0
        last=len(nums)-1
        while first<last:
            mid=(last+first)//2
            if nums[mid]>nums[last]:
                first=mid+1
            elif nums[mid]<nums[last]:
                last=mid
            else:
                last-=1
        return nums[first]