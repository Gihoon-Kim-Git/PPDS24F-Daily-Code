from collections import defaultdict as dd
class Solution:
    def frequencySort(self, s: str) -> str:
        d = dd(int)
        for k in s:
            d[k]+=1
        sorted_by_values_desc = sorted(d.items(), key=lambda item: item[1], reverse=True)
        ans=""
        for i in sorted_by_values_desc:
            ans+=i[0]*i[1]
        return ans