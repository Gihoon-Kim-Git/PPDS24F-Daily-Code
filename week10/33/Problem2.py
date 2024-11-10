# stone list가 주어졌을 때 alice와 bob이 stone을 하나씩 지우는 놀이를 함
# 이 때, 지워진 stone의 합이 3의 배수가 되면 마지막에 stone을 지운 사람이 짐 
# 만약 stone이 남지 않는다면 bob의 승리 
# Alice가 이기면 return True, Bob이 이기면 return False 

"""
solution 찾아봄
: 각 round에서 제거된 stone이 (1, 2)거나 (3, 3)이면 나머지 유지되므로 
 일단 제거해보기
 이후 -> : Alice가 이기는 경우 생각
"""
class Solution:
     def stoneGameIX(self, stones: List[int]) -> bool:
        stones = [v % 3 for v in stones]
        
        d = defaultdict(int)
        for v in stones:
            d[v] += 1
        
        while d[1] >= 2 and d[2] >= 2:
            d[2] -= 1
            d[1] -= 1
        
        if d[0] % 2 == 0:
            if (d[1] == 1 and d[2] >= 1) or (d[2] == 1 and d[1] >= 1):
                return True
        else:
            if (d[1] == 0 and d[2] >= 3) or (d[2] == 0 and d[1] >= 3):
                return True
            if (d[1] == 1 and d[2] >= 4) or (d[2] == 1 and d[1] >= 4):
                return True

        return False