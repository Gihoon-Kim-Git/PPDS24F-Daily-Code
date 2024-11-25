from typing import List

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = list(map(str, nums))
        
        n = len(nums)
        for i in range(n):
            for j in range(n - 1 - i):
                if nums[j] + nums[j + 1] < nums[j + 1] + nums[j]:
                    nums[j], nums[j + 1] = nums[j + 1], nums[j]
        
        # 숫자를 붙여서 큰 숫자로 만듦
        largest_num = ''.join(nums)
        
        # edge case 처리: 가장 큰 숫자가 0인 경우 0을 return
        if largest_num[0] == '0':
            return '0'
        
        return largest_num

sol = Solution()
print(sol.largestNumber([10,2,31,3]))
