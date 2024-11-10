class Solution(object):
    def findMin(self, nums):
        return self.findMinHelp(nums, 0, len(nums)-1)
    
    def findMinHelp(self, nums, start, end):
        if end - start == 0:
            return nums[start]
        mid = (start + end) // 2
        left = self.findMinHelp(nums, start, mid)
        right = self.findMinHelp(nums, mid+1, end)
        return min(left, right)

if __name__ == "__main__":
    nums = [1,3,5]
    # nums = [2,2,2,0,1]
    result = Solution()
    print(result.findMin(nums))