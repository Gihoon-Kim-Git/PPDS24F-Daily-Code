class Solution:
    def frequencySort(self, s: str) -> str:
        count = {}
        for ch in s:
            if ch in count:
                count[ch]+=1
            else:
                count[ch] = 1
        

        # Value 기준 내림차순 정렬
        d = dict(sorted(count.items(), key=lambda item: item[1], reverse=True))

        result = ''
        for i in d:
            result += i * d[i]
        return result


#%%
d = {"e" : 3, "f" : 5}
d = dict(sorted(d.items(), key=lambda item: item[1], reverse=True))
for i in d:
    print(i, d[i])



# %%
