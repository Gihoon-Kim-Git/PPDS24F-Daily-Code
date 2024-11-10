class Solution:
    def stoneGameIX(self, stones: list[int]) -> bool:
        count = [0, 0, 0]
        
        # 각 나머지 0, 1, 2로 돌을 그룹화하여 개수를 센다.
        for stone in stones:
            count[stone % 3] += 1
        
        # 나머지가 0인 돌의 개수가 짝수일 경우
        if count[0] % 2 == 0:
            # 나머지 1인 돌과 나머지 2인 돌이 모두 있는 경우 Alice가 이길 수 있다.
            return count[1] > 0 and count[2] > 0
        else:
            # 나머지가 0인 돌의 개수가 홀수일 경우
            # 나머지 1인 돌이 나머지 2인 돌보다 2개 이상 더 많거나,
            # 나머지 2인 돌이 나머지 1인 돌보다 2개 이상 더 많으면 Alice가 이길 수 있다.
            return abs(count[1] - count[2]) > 2