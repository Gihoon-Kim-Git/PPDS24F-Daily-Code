class Solution:
    def frequencySort(self, s: str) -> str:
        dct = dict()
        ans = ""
        for st in s:
            if st not in dct.keys():
                dct[st] = s.count(st)
        
        sorted_dct = sorted(dct.items(), key=lambda item: item[1], reverse = True)
        for num in sorted_dct:
            ans += num[0]*num[1]

        return ans
