"""Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string """

"""Constraints:
        1 <= strs.length <= 200
        0 <= strs[i].length <= 200
        strs[i] consists of only lowercase English letters."""
#★ longest common prefix란 "여러 문자열이 공유하는 가장 긴 앞쪽 공통 부분 문자열"

"""아이디어 다시 정리
    : 앞부분부터만 보면 됨.
    1) n = len(strs)
    2) dpT 정의 : 길이 n ※ dpT[i]는 dpT[i-1]과 strs[i]의 공통문자열 저장
    3) dpT 초기화 : dpT[0] = strs[0]
    4) dpT[i-1]과 strs[i]의 longest common prefix 찾는 방법
        shorter = dpT[i-1] if len(dpT[i-1]) < strs[i] else strs[i]
        longer = dpT[i-1] if len(dpT[i-1]) >= strs[i] else strs[i]
        
        while문 돌면서 shorter의 길이가 1이상인 동안 아래 반복
            common_length = len(shorter)
            if longer[:common_length] == shorter :
                dpT[i] = shorter
                break
            else :
                shorter = shorter[:-1] #마지막 글자 빼고 재검사   

    5) return dpT[n-1]
"""

#%%
## 통과
class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:  
        n = len(strs)
        dpT = ["" for _ in range(n)]
        
        dpT[0] = strs[0]

        for i in range(1,n):
            shorter = dpT[i-1] if len(dpT[i-1]) < len(strs[i]) else strs[i]
            longer = dpT[i-1] if len(dpT[i-1]) >= len(strs[i]) else strs[i]
            while len(shorter)>= 1:
                if longer[:len(shorter)] == shorter :
                    dpT[i] = shorter
                    break
                else :
                    shorter = shorter[:-1]
                                        
        return dpT[n-1]

#strs = ["flower","flow","flight"] #"fl"
strs = ["reflower","flow","flight"]  # ""
sol = Solution()
print(sol.longestCommonPrefix(strs))


#%%
#다른 풀이 1
class Solution:
    def longestCommonPrefix(self, v: List[str]) -> str:
        ans=""
        v=sorted(v) #sort를 하면 사전순으로 정렬됨. 그러면 가장 앞에 있는 문자열과 가장 뒤에  있는 문자열이 공유하는 공통 접두사는 그 배열에 속한 모든 문자열의 공통 접두사가 됨. #따라서 모든 문자열 쌍 검사할 필요없이 첫번째 문자열과 마지막 문자열만 검사하면 됨.
        first=v[0]
        last=v[-1]
        for i in range(min(len(first),len(last))):
            if(first[i]!=last[i]):
                return ans
            ans+=first[i]
        return ans 


# 다른풀이2 
class Solution:
    def longestCommonPrefix(self, strs):
        n = len(strs)
        prefix = strs[0]
        new_prefix = -1
        for j in range(1, n):
            word = strs[j]
            for i in range(min(len(prefix), len(word))):
                if word[i] != prefix[i]:
                    new_prefix = i #새로운 prefix 길이를 저장하는 변수
                    break
            if new_prefix != -1:
                prefix = prefix[:new_prefix]
            elif len(prefix) > len(word):
                prefix = word
        
        return prefix

    
#%%

"""아이디어1 : 틀림. Longest Comomn Prefix 의미를 잘못 이해함.
    :DP를 활용해서 앞에서부터 차례로 찾아가는 방식(Bottomup)
    1) n = len(strs)
    2) dpT 정의 : 길이 n ※ dpT[i]는 dpT[i-1]과 strs[i]의 공통문자열 저장
    3) dpT 초기화 : dpT[0] = strs[0]
    4) dpT[i-1]과 strs[i]의 공통 문자열 찾는 방법
        shorter = dpT[i-1] if len(dpT[i-1]) < strs[i] else strs[i]
        longer = dpT[i-1] if len(dpT[i-1]) >= strs[i] else strs[i]
        for length in range(len(shorter)+1, -1, -1):
            for s in range(0, len(shorter)-length+1):
                e = s + length - 1
                if shorter[s:e+1] in longer :
                    dpT[i] = shorter[s:e+1]
                
    5) return dpT[n-1]
"""

### 아이디어 1 구현 :
class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:  
        n = len(strs)
        dpT = ["" for _ in range(n)]
        
        dpT[0] = strs[0]

        for i in range(1,n):
            shorter = dpT[i-1] if len(dpT[i-1]) < len(strs[i]) else strs[i]
            longer = dpT[i-1] if len(dpT[i-1]) >= len(strs[i]) else strs[i]
            found = False
            for length in range(len(shorter)+1, -1, -1):
                for s in range(0, len(shorter)-length+1):
                    e = s + length - 1
                    #print(shorter[s:e+1])
                    if shorter[s:e+1] in longer :
                        dpT[i] = shorter[s:e+1]
                        found = True
                        break # break는 맨 안쪽 for문만 break함.
                if found == True : #length에 대한 for문 종료를 위한 flag 처리
                    break
                                        
        return dpT[n-1]


strs = ["flower","flow","flight"]
sol = Solution()
print(sol.longestCommonPrefix(strs))
# 틀린 반례
strs = ["reflower","flow","flight"]  #답이 ""여야 하는데 "fl"되서 틀림.
# %%
