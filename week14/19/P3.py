class Solution1(object):
    def nextGreaterElement(self, nums1, nums2):
        h = {}
        for i in range(len(nums2)-1,-1,-1):
            if (i == len(nums2)-1):
                h[nums2[i]] = -1
            else:
                if (nums2[i] < nums2[i+1]):
                    h[nums2[i]] =  nums2[i+1]
                else:
                    iter = i
                    while (iter < len(nums2)-1):
                        h[nums2[i]] = -1
                        if (nums2[i] < h[nums2[iter+1]]):
                            h[nums2[i]] = h[nums2[iter+1]]
                            break
                        iter += 1
        answer = []
        for j in nums1:
            answer.append(h[j])
        return answer

class Solution2(object):
    def nextGreaterElement(self, nums1, nums2):
        answer = []
        stack = []
        h = {}
        for n in nums2:
            while stack and n > stack[-1]:
                h[stack.pop()] = n
            stack.append(n)
        for n in nums1:
            answer.append(h.get(n, -1))
        return answer

if __name__ == "__main__":
    result = Solution1()
    # result = Solution2()
    nums1 = [4,1,2]
    nums2 = [1,3,4,2]
    print(result.nextGreaterElement(nums1, nums2))
    nums1 = [2,4]
    nums2 = [1,2,3,4]
    print(result.nextGreaterElement(nums1, nums2))
    nums1 = [1,3,5,2,4]
    nums2 = [5,6,4,3,2,1,7]
    print(result.nextGreaterElement(nums1, nums2))
    nums1 = [3,1,2,4]
    nums2 = [3,1,2,4]
    print(result.nextGreaterElement(nums1, nums2))