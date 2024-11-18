# 단어 list가 주어졌을 때 단어들의 prefix 찾기

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        len_min = 0
        prefix = ""
        
        for word in strs:
            if len_min == 0 or len_min > len(word):
                len_min = len(word)
        
        for idx in range(len_min):
            if strs[0] == "":
                return prefix
            alp = strs[0][idx]
            for word in strs:
                if word == "":
                    return prefix
                if alp != word[idx]:
                    return prefix
            prefix += alp

        return prefix 


"""
GPT 코드
any 함수 - iterable 내에 하나 이상의 값이 True인 경우 True를 반환하고, 모두 False이면 False를 반환
"""
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        # 가장 짧은 문자열의 길이를 찾음
        min_length = min(len(word) for word in strs)
        
        # 각 위치의 문자를 동시에 비교
        for i in range(min_length):
            char = strs[0][i]
            if any(word[i] != char for word in strs):
                return strs[0][:i]
        
        # 모든 문자가 일치하면 가장 짧은 문자열이 공통 접두사
        return strs[0][:min_length]


"""
다른 user 코드
: 첫번째 단어를 prefix로 설정하고 prefix가 아닌 부분을 뒤에서부터 없애나감
"""
class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        if not strs:
            return ""
        prefix = strs[0]
        for s in strs[1:]:
            while not s.startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return ""
        return prefix