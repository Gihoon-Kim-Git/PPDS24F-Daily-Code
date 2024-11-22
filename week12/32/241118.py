class Solution:
    def frequencySort(self, s: str) -> str:
        dic = dict()
        ans = ""
        for i in range(len(s)):
            if s[i] not in dic:
                dic[s[i]] = 1
            else:
                dic[s[i]] += 1

        sorted_dict = dict(sorted(dic.items(), key=lambda item: item[1], reverse=True))
        
        for key,value in sorted_dict.items():
            ans += key * value

        return ans
