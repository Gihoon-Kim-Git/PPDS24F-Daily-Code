class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1

        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[right]:
                # minimum must be in the right part
                left = mid + 1
            elif nums[mid] < nums[right]:
                # minimum must be in the left part
                right = mid
            else:
                right -= 1
        return nums[left]