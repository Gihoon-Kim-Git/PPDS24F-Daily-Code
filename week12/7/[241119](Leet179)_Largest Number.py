"""Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
    Since the result may be very large, so you need to return a string instead of an integer.

Example 1:
    Input: nums = [10,2]
    Output: "210"
    
Example 2:
    Input: nums = [3,30,34,5,9]
    Output: "9534330"

Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 109"""

"""아이디어
    1. 일단 nums의 모든 요소를 문자로 바꿔주고 내림차순 정렬한다.(그럼 앞자리 수 기준으로 나열됨)
    2. 답이 될 문자열을 하나 정의한다. 초기화는 빈칸으로.
    3. sort가 완료된 nums를 처음부터 끝까지 돌면서 answer에 값을 추가하는 과정
        여기서 어려운 점... 앞자리가 같을 때에 어떻게 처리할 것인가...
"""

"""다른 풀이 참고
    ★ 이 문제의 본질 : x + y, y + x 결과를 직접 비교한 결과를 토대로 sort.
"""


class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        
        for i in range(len(nums)) :
            nums[i] = str(nums[i])
        
        #x*10은 문자열의 확장을 통해 두 문자열을 충분히 길게 만듦으로써, x+y, y+x의 비교를 처리할 수 있음. (ex. 3*10 : 3333333333 과 30 * 10 : 3030303030330303030 이 둘이 사전순으로 비교되면 3이 앞에 옴.)
        nums.sort(key = lambda x : x*10, reverse = True) 
        
        result = ''.join(nums)
        
        # "000"과 같은 경우 처리 (모두 0인 경우)
        return result if result[0] != '0' else '0'
                









#%%
list = ['3','34','32','51','35','9']
list.sort(reverse = True)
print(list) #['9', '51', '35', '34', '32', '3']


# %%
