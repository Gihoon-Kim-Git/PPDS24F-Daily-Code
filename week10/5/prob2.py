class Solution:
    # stone 의 value 를 3으로 나눈 나머지는 0, 1, 2 중 하나이다.
    # 나머지가 0, 1, 2 인 stone 의 개수를 각각 a, b, c 라고 하자.
    
    #    1 turn : Alice 는 반드시 b, c 로 시작한다. (b=c=0 이라 불가능하면 A 패배)
    
    # last turn 으로 가능한 경우의 수
    # - 1. a를 집고 3의 배수가 된 경우 : 불가능. 그 전 턴에 이미 3배수이므로
    # - 2. a를 집고 남은 돌이 없는 경우 : A 패배
    # - 3. b/c 를 집고 3의 배수가 된 경우 : 마지막 턴이었던 사람의 패배
    # - 4. b/c 를 집고 남은 돌이 없는 경우 : A 패배

    # Alice 가 승리할 수 있는 유일한 경우의 수
    # - Bob이 자신의 turn에, b/c 중 3의 배수가 되는 stone (say b) 이외에는 남아있는 돌 (say a, c) 이 없어서 그걸 집는 경우
    # 위 경우일 때 가능한 게임의 양상
    # - 1. b (bc+[a]) c
    # - 2. b (bc+[a]) bb

    # Alice 의 승리를 위한 필요조건으로서 1 turn 의 행동
    # - a 가 짝수개인 경우
    # -- 1 경우를 발동시켜야 함 : b/c 중 개수가 더 적은 것을 고른다.
    # - a 가 홀수개인 경우
    # -- 2 경우를 발동시켜야 함 : b/c 중 개수가 더 많은 것을 고른다.
    # 즉, 언제나 승리 가능

    # 위 시나리오가 불가능한 경우에만 Alice 가 패배
    # - 1 이 불가능한 경우
    # -- a 가 짝수개 [AND] b=0 or c=0
    # - 2 가 불가능한 경우
    # -- a 가 홀수개 [AND] b/c 개수 차이가 3개 미만

    def stoneGameIX(self, stones: list[int]) -> bool:
        cnt_residual_0 = 0
        cnt_residual_1 = 0
        cnt_residual_2 = 0
        for value in stones:
            if value % 3 == 0:
                cnt_residual_0 += 1
            elif value % 3 == 1:
                cnt_residual_1 += 1
            else:
                cnt_residual_2 += 1
        
        # 시나리오 1 이 불가능한 경우
        if cnt_residual_0 % 2 == 0:
            if cnt_residual_1 == 0 or cnt_residual_2 == 0:
                return False
            else:
                return True
        # 시나리오 2 가 불가능한 경우
        else:
            if abs(cnt_residual_1 - cnt_residual_2) < 3:
                return False
            else:
                return True
