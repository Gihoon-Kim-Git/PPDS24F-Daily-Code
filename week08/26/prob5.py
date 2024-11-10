class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        
        while left < right:
            mid = left + (right - left) // 2
            
            if nums[mid] > nums[right]:
                # Minimum must be in the right half
                left = mid + 1
            elif nums[mid] < nums[right]:
                # Minimum could be at mid or in the left half
                right = mid
            else:
                # nums[mid] == nums[right], cannot determine the side; reduce right
                right -= 1
    
        return nums[left]
        