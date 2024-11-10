# 정렬되어 있다는 사실 이용


def findMin(nums):
    left, right = 0, len(nums)-1
    
    while left < right:
        mid = (left+right)//2

        if nums[mid] < nums[right]:
            right = mid          # 최솟값 왼쪽에 있을 가능성 큼
        elif nums[mid] > nums[right]:   # 최솟값 오른쪽에 있을 가능성 큼 (당연히 mid는 아님. nums[right]이 더 작음)
            left = mid + 1
        else:    # 중복값 있으면 건너뜀
            right -= 1
        
    return nums[left]


print(findMin([1,3,5]))  # 1
print(findMin([2,2,2,0,1]))  # 0
