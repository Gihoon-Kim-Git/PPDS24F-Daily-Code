"""Seven different symbols represent Roman numerals with the following values:

    Symbol	Value
    I	1
    V	5
    X	10
    L	50
    C	100
    D	500
    M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:
    -- If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
    -- If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
    -- Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
    
Given an integer, convert it to a Roman numeral."""

"""Constraints:
    1 <= num <= 3999"""

"""규칙을 정리해보자
    1. 만약 num이 4 또는 9로 시작하면, subtractive form을 사용.
        : 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM). 
    2. 10의 배수들만 3번 연속해서 쓰일 수 있다. 
        : I, X, C, M
        : 5 (V), 50 (L), or 500 (D) 들은 연속해서 쓰일수없음.
    3. 만약 4 또는 9로 시작하지 않는다면, 주어진 숫자에서 roman numeral로 표현할 수 있는 최댓값을 빼고, 남은 값에서 roman numeral로 최대만큼 표기하고 또 다시 빼고하는 과정을 반복.
"""

"""수도코드
목표 : 주어진 수를 3가지 원칙에 맞추어 roman numeral 표기를 반환

1. 좀더 편리하게 매칭되는 값을 반환하기 위해서 dictionary 생성
    { 4 : "IV", 9 : "IX", 40 : "XL", 90 : "XC", 400 : "CD", 900 : "CM", 1 : "I", 5 : "V", 10 : "X", 50 : "L", 100 : "C", 500 : "D", 1000 : "M"}

2. 생성할 romanN = "" 초기화

3. 아래를 while문 돌면서 반복.(num이 0이 되면 중단)
    str_num = str(num)
    cur_sub = 0
    4-1.   str_num의 첫 글자가 만약 4 라면?
            일단 str_num의 길이 확인해서 길이별로 해당되는 dictionary 값을 romanN에 append.
            cur_sub 업데이트
            
    4-2    str_num의 첫 글자가 만약 9라면?
            일단 str_num의 길이 확인해서 길이별로 해당되는 dictionary 값을 romanN에 append.
            cur_sub 업데이트

    4-3. str_num의 첫 글자가 4,9가 아니라면? (Else)
        만약 str_num의 첫 글자가 3이하(1,2,3)인 경우.
            str_num의 길이가 한 자리이면 dic[1]을 글자갯수만큼
            str_num의 길이가 두 자리이면 dic[10]을 글자갯수만큼
            str_num의 길이가 두 자리이면 dic[100]을 글자갯수만큼
            str_num의 길이가 세 자리이면 dic[1000]을 글자갯수만큼
            cur_sub 업데이트
        만약 str_num의 첫 글자가 5~8인 경우
            str_num의 길이가 한 자리이면 
                dic[5]를 일단 append.
                그리고 dic[1]을 글자갯수(첫글자-5)만큼
            str_num의 길이가 두 자리이면 dic[10](첫글자-5)을 글자갯수만큼   
                dic[50]를 일단 append.
                그리고 dic[10]을 글자갯수(첫글자-5)만큼
            str_num의 길이가 두 자리이면 dic[100](첫글자-5)을 글자갯수만큼
                dic[500]를 일단 append.
                그리고 dic[100]을 글자갯수(첫글자-5)만큼
        num -= cur_sub

5. 결과 반환 : return romanN
"""
#%%
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        dic_4 = {1 : "IV", 2 : "XL", 3 : "CD"}
        dic_9 = {1 : "IX", 2 : "XC", 3 : "CM"}
        dic_1 = {1 : "I",  2 : "X",  3 : "C", 4 : "M"}
        dic_5 = {1 : "V", 2 : "L", 3 : "D"}
        romanN = ""
        
        while num > 0 :
            str_num = str(num)
            cur_sub = 0
            if str_num[0] == '4' :
                romanN += dic_4[len(str_num)]
                cur_sub_str = '4'+ '0'*(len(str_num)-1)
                cur_sub = int(cur_sub_str)
            elif str_num[0] == '9':
                romanN += dic_9[len(str_num)]
                cur_sub_str = '9'+ '0'*(len(str_num)-1)
                cur_sub = int(cur_sub_str)
            elif str_num[0] in "123" :
                times = int(str_num[0])
                romanN += dic_1[len(str_num)] * times
                cur_sub_str = str_num[0] + '0' * (len(str_num) -1)
                cur_sub = int(cur_sub_str)
            else :
                times = int(str_num[0]) - 5
                romanN += dic_5[len(str_num)]
                romanN += dic_1[len(str_num)] * times
                cur_sub_str = str_num[0] + '0' * (len(str_num) -1)
                cur_sub = int(cur_sub_str)
            
            num -= cur_sub
        
        return romanN


sol1 = Solution()
print(sol1.intToRoman(58)) #LVIII
print(sol1.intToRoman(1994)) #MCMXCIV
print(sol1.intToRoman(3749)) #MMMDCCXLIX


        
# %% 다른 풀이

answer = ""
roman = {모든 거 dictionary}
while (num > 0) :
    for r in roman:
        if (num >= r):
            answer += roman[r]:
                answer += roman[r]
                num -= r
                break
return answer
