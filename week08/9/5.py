class Solution:
    def findMin(self, nums: list[int]) -> int:
        s = 0
        for i in range(len(nums)-1):
            if nums[i] > nums[i+1]:
                s = i
                break
        else :
            return nums[0]
        
        return nums[i+1]