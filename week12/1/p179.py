class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """        
        nums = list(map(str, nums))

        def compare(str1, str2):
            if str1 + str2 > str2 + str2:
                return -1 # str1이 str2보다 앞에 오게 순서를 '바꾸지 않음'
            
            elif str1 + str2 < str2 + str1:
                return 1 # str2가 str1보다 앞에 오게 순서를 '바꿈'

            else:
                return 0 # 순서가 상관 없음

        nums.sort(key=cmp_to_key(compare))        

        result = ''.join(nums)

        return result