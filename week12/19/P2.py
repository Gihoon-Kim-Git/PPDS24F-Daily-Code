class Solution(object):
    def largestNumber(self, nums):
        answer = ""
        if not nums:
            return answer
        if len(nums) == 1:
            return str(nums[0])
        nums = self.largestNumberHelp(nums)
        for i in nums:
            answer += str(i)
        return str(int(answer))

    def largestNumberHelp(self, lists):
        if len(lists) == 1:
            return lists
        mid = len(lists) // 2
        left = self.largestNumberHelp(lists[:mid])
        right = self.largestNumberHelp(lists[mid:])
        return self.merge(left, right)
    
    def merge(self, list1, list2):
        merge_list = []
        i = 0
        j = 0
        while i < len(list1) and j < len(list2):
            merge_num1 = str(list1[i]) + str(list2[j])
            merge_num2 = str(list2[j]) + str(list1[i])
            if merge_num1 > merge_num2:
                merge_list.append(list1[i])
                i += 1
            else:
                merge_list.append(list2[j])
                j += 1
        if i < len(list1):
            merge_list = merge_list + list1[i:]
        if j < len(list2):
            merge_list = merge_list + list2[j:]
        return merge_list

if __name__ == "__main__":
    nums1 = [10, 2]
    nums2 = [3, 30, 34, 5, 9]

    answer = Solution()
    print(answer.largestNumber(nums1))
    print(answer.largestNumber(nums2))