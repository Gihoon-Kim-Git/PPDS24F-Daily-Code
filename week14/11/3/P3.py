class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        for i in range(len(nums1)):
            for j in range(len(nums2)):
                if nums2[j] == nums1[i]:
                    cur = j
                    break
            
            flag = 1
            for k in range(cur, len(nums2)):
                if nums2[k] > nums2[cur]:
                    ans.append(nums2[k])
                    flag = 0
                    break
            if flag:
                ans.append(-1)
        return ans