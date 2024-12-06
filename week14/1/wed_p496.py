class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        result = []
        def _find_first_greater_idx(L, num):
            if len(L) > 0:
                for i in range(len(L)):
                    if L[i] > num: 
                        return L[i]
                    else: 
                        pass
            return -1

        def _find(L, num):
            for idx in range(len(L)):
                if L[idx] == num: return idx
                else: pass

        for num in nums1:
            j = _find(nums2, num)
            i = _find_first_greater_idx(nums2[j+1:], num)
            print(num, i, j)
            if i == -1:
                result.append(-1)
            else:
                result.append(i)
        return result