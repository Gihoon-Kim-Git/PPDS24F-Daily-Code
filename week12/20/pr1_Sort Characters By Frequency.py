class Solution:
    def frequencySort(self, s: str) -> str:
        dic = {}
        for ch in s :
            if ch not in dic :
                dic[ch] = 1
            else : dic[ch]+=1
        ans = ""
        while dic:
            temp = 0
            ch = ''
            for alpha,freq in dic.items():
                if freq > temp :
                    temp = freq
                    ch = alpha
            dic.pop(ch)
            ans += ch*temp
        return ans
    
from collections import Counter
# class Solution:
#     def frequencySort(self, s: str) -> str:
#         freq=Counter(s)
#         sor_char=sorted(freq.items(), key=lambda item : item[1], reverse=True)
#         result=''.join(char*count for char,count in sor_char)
#         return result
s= "zasdasddasfasdfasdasdf asdasfasdasd"
freq = Counter(s)
print(freq)
print(freq.items())
# # print(freq.keys())
# # # print(freq.keys())
freq2=sorted(freq.items(),key = lambda x:x[1],reverse=True)
print(sorted(freq.items(),key = lambda x:x[1],reverse=True))
print(type(freq2[0]))
# for x,y in freq.items():
#     print(x,type(x))
#     print(y,type(y))

# freq2 = sorted(freq,reverse=True)
# print(freq2)
# print(freq[3])
