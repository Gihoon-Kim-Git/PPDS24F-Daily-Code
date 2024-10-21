class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        print(nums)
        if n==1:
            return nums[0]
        mid=-1
        for i in range(n-1):
            if nums[i]>nums[i+1]:
                mid =i
        if mid==-1:
            return nums[0]
        return self.findMin(nums[mid+1:])