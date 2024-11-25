class Solution:
    def largestNumber(self, nums: list[int]) -> str:
        # 모든 숫자를 문자열로 변환
        nums = list(map(str, nums))
        
        # 문자열 조합 비교를 통해 정렬
        nums.sort(key=lambda x: x*10, reverse=True)
        
        # 정렬된 숫자를 연결
        ans = ''.join(nums)
        
        # 결과가 '0'으로 시작하면 '0' 반환
        return '0' if ans[0] == '0' else ans


# class Solution:
#     def largestNumber(self, nums: List[int]) -> str:
#         ans = ""
#         # make them all string
#         for i in range(len(nums)):
#             nums[i] = str(nums[i])
#         while nums:
#             temp = '0'
#             for x in nums:
#                 if x[0] > temp[0]:
#                     temp = x
#                 elif x[0] == temp[0]:
#                     if x == temp : continue

#                     idx = 0
#                     cond = True
#                     n1 = len(x) # 830 , 1113
#                     n2 = len(temp) # 8308 , 111311
#                     while idx < n1 and idx < n2:
#                         if x[idx] > temp[idx]:
#                             temp = x
#                             cond = False
#                             break
#                         elif x[idx] < temp[idx]:
#                             cond = False
#                             break
#                         idx+=1
#                     if cond:
#                         if len(x) > len(temp):
#                             if x+temp > temp+x :
#                                 temp = x
#                         else:
#                             if temp+x < x+temp :
#                                 temp = x
#             if ans != '0':
#                 ans+=temp
#             nums.remove(temp)

#         return ans
