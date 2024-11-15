#%%
class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        out = ""
        min_len = 200
        # 가장 최소길이 str 찾기 
        for i in range(len(strs)):
            if min_len > len(strs[i]):
                min_len = len(strs[i])
                x = i

        # 가장 짧은 str 돌면서 다른 스트링이랑 다 같으면 out에 추가
        # 아니면 끝내고 return
        for i in range(min_len):
            flag = True
            for j in range(len(strs)):
                if strs[x][i] != strs[j][i]:
                    flag = False
            
            if not flag:
                break

            out += strs[x][i]

        return out
