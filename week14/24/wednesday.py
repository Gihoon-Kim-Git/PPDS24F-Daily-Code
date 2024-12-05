# Next Greater Element I

from typing import List

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # O(n+m) solution
        stack = []
        hashMap = {}
        answer = []

        for num in nums2: # nums2 is the array to find next greater element
            while stack and num > stack[-1]: # if current number is greater than the top of stack
              hashMap[stack.pop()] = num # pop the top of stack and add to hashMap
            stack.append(num) # push current number to stack

        for el in nums1: # nums1 is the array to find next greater element from nums2
            if el in hashMap: # if the element is in hashMap
                answer.append(hashMap[el]) # add the next greater element to answer
            else:
                answer.append(-1) # if the element is not in hashMap, add -1 to answer

        return answer

if __name__ == "__main__":
    sol = Solution()
    print(sol.nextGreaterElement([4,1,2], [1,3,4,2]))
    print(sol.nextGreaterElement([2,4], [1,2,3,4]))
