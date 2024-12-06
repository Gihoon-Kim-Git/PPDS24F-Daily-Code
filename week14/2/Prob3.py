from typing import List

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # index를 찾고, 그 오른쪽부터 해당 값보다 큰 값이 존재하면 해당 수를 리턴
        # 더 큰 수가 없다면 -1을 리턴
        
        # define find index
        def find_index(num: int, nums2: List[int]) -> int:
            for i, n in enumerate(nums2):
                if num == n:
                    return i
        # define return next greater element function
        def NGE(num: int, i: int, nums2: List[int]) -> int:
            for j in range(i, len(nums2)):
                if nums2[j] > num:
                    return nums2[j]
            return -1

        # check next greater element
        result = []
        for n in nums1:
            result.append(NGE(n, find_index(n, nums2), nums2))
        return result