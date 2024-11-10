class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        cnt = Counter(s % 3 for s in stones)
        if cnt[0] % 2 == 0:
            if cnt[1] == 0 or cnt[2] == 0:
                return False
            else:
                return True
        
        elif cnt[0] % 2 == 1:
            return abs(cnt[1] - cnt[2]) >= 3