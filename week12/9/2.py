def compare(x, y):
    return x+y > y+x

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        ans = ""
        str_nums = list(map(str, nums))

        for i in range(len(str_nums)):
            for j in range(len(str_nums)-1):
                if not compare(str_nums[j], str_nums[j+1]):
                    str_nums[j], str_nums[j+1] = str_nums[j+1], str_nums[j]
        
        largest_num = ''.join(str_nums)

        return '0' if largest_num[0] == '0' else largest_num
