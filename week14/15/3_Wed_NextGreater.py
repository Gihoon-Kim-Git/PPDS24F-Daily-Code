from typing import List

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = [-1] * len(nums1)
        nums1_idx = {n:i for i, n in enumerate(nums1)}      # [4, 1, 2] => {4:0, 1:1, 2:2}

        for i in range(len(nums2)):
            if nums2[i] not in nums1_idx:
                continue
            for j in range(i+1, len(nums2)):
                if nums2[j] > nums2[i]:
                    idx = nums1_idx[nums2[i]]       # nums1_idx에서 nums2[i]의 인덱스(idx)를 가져옴 
                    res[idx] = nums2[j]
                    break
        return res