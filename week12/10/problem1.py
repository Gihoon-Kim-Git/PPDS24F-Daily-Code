from collections import defaultdict

class Solution:
    def frequencySort(self, s: str) -> str:
        
        lib = defaultdict(list)
        
        for i in s:
            lib[i].append(i)
        
        lib_l = []
        for l in range(len(s)+1, 0, -1):
            for i in lib:
                if len(lib[i]) == l:
                    lib_l += lib[i]
        
        ans = "".join(lib_l)

        return ans