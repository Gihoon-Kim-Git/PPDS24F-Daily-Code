class Solution(object):
    def stoneGameIX(self, stones):
        stoneDict = {0:0, 1:0, 2:0}
        for s in stones: # 0,1,2 dict으로 전환
            num = s % 3
            stoneDict[num] += 1
        if (stoneDict[0] % 2 == 0): # 0이 짝수일때
            if (stoneDict[1] > 0 and stoneDict[2] > 0): # 선턴 잡으면 끝
                return True
            else:
                return False
        else: # 0이 홀수일때
            if (abs(stoneDict[1] - stoneDict[2]) > 2): # 턴이 한번 넘어가므로 2개 넘어가도록 차이가 발생해야 함
                return True
            else:
                return False

if __name__ == "__main__":
    result = Solution()
    stones = [2]
    print(result.stoneGameIX(stones)) # False
    stones = [2,1]
    print(result.stoneGameIX(stones)) # True
    stones = [2,2]
    print(result.stoneGameIX(stones)) # False
    stones = [0]
    print(result.stoneGameIX(stones)) # False
    stones = [2,0]
    print(result.stoneGameIX(stones)) # False
    stones = [2,1,0]
    print(result.stoneGameIX(stones)) # False
    stones = [2,2,0]
    print(result.stoneGameIX(stones)) # False
    stones = [2,2,2,0]
    print(result.stoneGameIX(stones)) # True