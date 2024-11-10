class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        count = [0, 0, 0]
        
        for stone in stones:
            # remainder count list(divided by 3)
            count[stone % 3] += 1
        
        # 만일 count[0] % 2 == 0이면, 3의 배수인 stone이 없거나 even하게 출현한 것임.
        # 3의 배수인 stone은 승패에 크게 영향은 없으며, count[1] 과 count[2] 의 개수에 의해 alice의 승패가 결정지어짐
        if count[0] % 2 == 0:
            return count[1] >= 1 and count[2] >= 1
        else:
            # If count[0] is odd, then the result depends on whether count[1] and count[2]
            # 만일 count[0]이 홀수개 존재하는 경우, Alice가 이기려면 count[1]과 count[2]의 개수가 충분히 차이나야 함
            return abs(count[1] - count[2]) > 2