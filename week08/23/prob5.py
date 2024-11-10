# Find Minimum in Rotated Sorted Array II
def findMin(nums):
    low, high = 0, len(nums) - 1
    
    while low < high:
        mid = low + (high - low) // 2
        
        if nums[mid] < nums[high]:
            high = mid
        elif nums[mid] > nums[high]:
            low = mid + 1
        else:
            high -= 1  # When nums[mid] == nums[high], reduce the search space
    
    return nums[low]
