class Solution:
    def frequencySort(self, s: str) -> str:
        # dictionary에 각 char의 출현횟수를 value로 저장
        fsort = dict()
        for char in s:
            if fsort.get(char, False):
                fsort[char] += 1
            else:
                fsort[char] = 1
        
        # value값을 기준으로 key값을 sorting
        sorted_fsort = sorted(fsort, key=lambda x:fsort[x], reverse=True)
        result = ""
        
        # sorting순서대로, 출현횟수만큼 key값을 연속적으로 기록
        for key in sorted_fsort:
            for _ in range(fsort[key]):
                result += key
        
        return result
    
sol = Solution()
print(sol.frequencySort("tree"))