# sorted array가 x번 roate되어 주어졌을 때
# orinal) [a[0], a[1], ... a[n-1]], rotated once) [a[n-1], a[0], ... a[n-2]]
# array의 minimum element 찾기

class Solution:
    def findMin(self, nums: List[int]) -> int:
        ans = nums[0]
        for i in nums:
            if i < ans:
                ans = i
                break
        return ans