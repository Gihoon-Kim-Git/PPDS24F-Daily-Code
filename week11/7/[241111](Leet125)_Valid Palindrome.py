"""A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise."""

"""Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters."""

"""아이디어
    1. input으로 들어온 문자열을 palindrome 검사하기 용으로 만들기. (검사용 문자열 생성)
        (소문자, 숫자이면 남기고. 대문자는 소문자로 변환, 나머지는 없애기)
    2. palindrome인지 여부를 검사하는 함수 생성.
        1) 중간에서부터 양끝단으로 이동하면서 한글자씩 확인하는 함수
            만약 홀수이면 중간 하나에서부터 시작
            만약 짝수이면 중간 두개에서부터 시작해서 각각 앞, 뒤로 이동하면서 같은 글자인지 봄.
                만약 다른 글자이면 바로 return false. 
                끝까지 다 돌았는데도 false를 반환하지 않았으면 True임.
        2) Recursive
            Base : 
                처음 index > 끝 index이면 True 
                처음 index, 끝 index 같으면 True 다르면 False
                처음 index + 1과 끝 index의 글자가 같으면 True.
                양 끝(처음, 끝)이 다를 경우, return False
            Recursive :
                양 끝(처음, 끝)이 같을 경우, 사이즈를 2 줄여서 (처음+1, 끝-1)도 Palindrome인지 결과 반영.
                
        3) DP (Bottom up)
            DP[i][j] : 문자열의 i번째 문자부터 j번째 문자까지가 팰린드롬인지 여부 저장 (T/F)
            초기화 : 모든 길이 1인 부분 문자열은 팰린드롬. (DP[i][i] = True)
            길이 2인 부분문자열 확인 : 두 문자가 같다면 팰린드롬 (DP[i][i+1] = s[i] == s[i+1])
            길이가 3이상인 경우 검사를 위한 점화식 : DP[i][j] = (s[i]==s[j] && DP[i+1][j-1])
            return DP[0][n-1]
"""

"""수도코드
목표 : input으로 들어온 문자열을 적절한 형태로 변환한 후, is_palindrome()함수에 넣고 결과 반환

1. 입력처리
    text4check = ""
    text 안의 글자를 하나씩보면서 숫자이거나 소문자이면 text4check에 append. 대문자이면 소문자로 변환 후 append

2. isPalindrome_help(text:str, start, end)-> bool 함수 정의
    1) base case
        start > end이면 return True (계속 True여서 지금까지 왔다는 거니까)
        들어온 text[start:end+1]의 길이가 1이면 return True
        들어온 text[start:end+1]의 길이가 2일 경우
            만약 두 글자가 같으면 return True
            만약 두 글자가 다르면 return False
        만약 text[start] != text[end]이면 False
    2) recursive case 
        들어온 text[start:end+1]의 길이가 3이상일 경우이면서 text[start] == text[end]일 경우
            return isPalindrome_help(text, start+1, end-1)

3. 결과반환
    return isPalindrome_help(text4check, 0, len(text4check)-1)
"""

## 아래와 같이 더 간단하게 정의할수도 있다.
    # 재귀 함수 정의
def is_palindrome_recursive(text, start, end) -> bool:
    if start >= end:
        return True
    if text[start] != text[end]:
        return False
    return is_palindrome_recursive(text, start + 1, end - 1)

def isPalindrome(self,s):
    cleaned_text = ''.join(c.lower() for c in s if c.isalnum())
    return is_palindrome_recursive(cleaned_text ,0,len(cleaned_text)-1)

#--------------------------------------------------------------------------------------
## Recursive하게 푼 풀이
class Solution(object):
    def isPalindrome(self, s):
        text4check = ""
        for c in s :
            if 48<=ord(c)<=57 or 97<=ord(c)<=122 :
                text4check += c
            elif 65 <= ord(c) <=90 :
                text4check += c.lower()
        
        def isPalindrome_help(text, start, end)->bool:
            if start > end :
                return True
            if len(text[start:end+1]) == 1 :
                return True
            if len(text[start:end+1]) == 2 and text[start] == text[end] :
                    return True
            if text[start] != text[end] :
                return False
            
            if len(text[start:end+1]) >= 3 and text[start] == text[end]:
                return isPalindrome_help(text, start+1, end-1)
        
        return isPalindrome_help(text4check,0,len(text4check)-1)

#--------------------------------------------------------------------------------------

## DP로 풀이 : Memory limit exceeded (480/486)
class Solution(object):
    def isPalindrome(self,s):
        cleaned_text = ''.join(c.lower() for c in s if c.isalnum())
        
        n = len(cleaned_text)
        if n <= 1:
            return True  # 빈 문자열 또는 단일 문자는 팰린드롬으로 처리

        dpT = [[False for _ in range(n)] for _ in range(n)]

        for i in range(n):
            dpT[i][i] = True
        
        for i in range(n-1):
            dpT[i][i+1] = cleaned_text[i] == cleaned_text[i+1]
        
        for length in range(3, n+1):
            for i in range(n-length+1):
                j = i + length - 1
                if cleaned_text[i] == cleaned_text[j] and dpT[i+1][j-1]:
                    dpT[i][j] = True
        return dpT[0][n-1]

                
#%%
#--------------------------------------------------------------------------------------

## 중간에서부터 두 개 포인터로 양끝단까지 이동하며 팰린드롬 판단
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        """문제해결전략
        0)만약 공백이면 return true
        1)공백이랑, 알파벳 및 숫자 아닌 거 다 제거. (이것을 어떻게 간단하게 코드로 표현하나?)
        2)모두다 lowercase로 바꿈
        3)palindrome인지 여부는 중간지점을 시작점으로해서, 포인터를 끝까지 옮겨가면서 체크
            - 만약 전체 길이가 짝수이면 (len 4 -> index 1,2) (len 10 -> 4,5) right = len//2, left = right - 1
            - 만약 전체 길이가 홀수이면 (len 5 -> 2) (len 9 -> 4) left, right = len//2, left = right
            - 끝에도달? left가 0이면 그게 마지막 확인임. 
            - 끝에 도달하기 전까지 비교할 것은 phrase[left] == phrase[right] -> 만약 true이면 left--, right++하고 false이면 return false"""
        
        lower_num_set = 'abcdefghijklmnopqrstuvwxyz0123456789'
        uppercase_set = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

        s_only_alpha = ""
        for char in s:
            if char in uppercase_set:
                char = char.lower()
            if char in lower_num_set:
                s_only_alpha += char
        
        length = len(s_only_alpha)
        if length == 0 or length == 1:
            return True
        right = length//2
        if length%2 == 0:
            left = right -1
        else:
            left = right
        
        while left >= 0 :
            if s_only_alpha[left] == s_only_alpha[right] :
                left -= 1
                right += 1
            elif s_only_alpha[left] != s_only_alpha[right]:
                return False
            
        return True