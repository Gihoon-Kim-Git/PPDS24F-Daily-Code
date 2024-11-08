"""문제
Alice and Bob continue their games with stones. There is a row of n stones, and each stone has an associated value. You are given an integer array stones, where stones[i] is the value of the ith stone.

Alice and Bob take turns, with Alice starting first. On each turn, the player may remove any stone from stones. The player who removes a stone loses if the sum of the values of all removed stones is divisible by 3. Bob will win automatically if there are no remaining stones (even if it is Alice's turn).

Assuming both players play optimally, return true if Alice wins and false if Bob wins."""

"""Constraints:
    1 <= stones.length <= 105
    1 <= stones[i] <= 104"""

"""다른 풀이
    0 : 0은 skip권이다. -> 짝수(상쇄)인건지, 홀수인건지 여부가 중요함.
    1,2 : 개수가 충분하면 먼저 둔 사람이 알아서 잘 조절해서 상대방이 3의 배수를 만드는 걸 못 피하도록 만들 수 있다.
        --유리하게 선택하는 방법--
            --- Alice는 다음과 같은 조건을 만족하도록 돌을 선택합니다:
                    나머지 1의 돌이 1개 있고 나머지 2의 돌이 1개 이상 남아 있을 때.
                    또는 나머지 2의 돌이 1개 있고 나머지 1의 돌이 1개 이상 남아 있을 때.
"""

## [방법1]
from collections import Counter

#Alice가 이기려면  최종 합이 3의 배수가 되지 않는 상태로 Bob에게 차례를 넘겨야 함. 이를 위해, Alice는 나머지 1과 2의 개수를 비교해서 적절하게 돌을 선택하는 것이 중요함.
class Solution:
    def stoneGameIX(self, stones) -> bool:
        cnt = Counter(s % 3 for s in stones)
        if cnt[0] % 2 == 0: #Alice가 항상 먼저 시작하는 상태로, 나머지 1과 2의 돌들을 자신에게 유리하게 사용할 수 있는 상태
            if cnt[1] == 0 or cnt[2] == 0: # 나머지 1이나 2에 해당하는 돌이 없으면 진다.
                return False
            else: #나머지 1과 나머지 2인 돌이 충분하면, 먼저 시작한 Alice가 유리하게 활용 가능.
                return True
        
        elif cnt[0] % 2 == 1:  # 먼저 시작하는 순서가 바뀔 수 있음. 
            return abs(cnt[1] - cnt[2]) >= 3  #한쪽의 개수가 3개 이상 많으면, Alice가 개수가 적은 쪽을 선택해서 Bob에게 불리한 상황을 강제할 수 있음. ex. 나머지 1이 나머지 2보다 2이상 많으면, Alice는 Bob이 돌아오는 순서에서 나머지 1이 남도록 게임을 진행할 수 있음. 

## [방법1-2]
import collections
class Solution:
    def stoneGameIX(self, stones):
        cnt = collections.Counter(a % 3 for a in stones)
        if cnt[0] % 2 == 0:
            return cnt[1] > 0 and cnt[2] > 0
        return abs(cnt[1] - cnt[2]) > 2

## [방법2]
import collections
class Solution:
    def stoneGameIX(self, stones):
        cnt = collections.Counter(a % 3 for a in stones)
        #나머지 1이나 나머지 2 중 하나가 0개일 경우, 나머지 돌만으로 Alice가 유리하게 게임을 진행할 수 있는지 확인
        ## 나머지1 또는 나머지 2 돌이 최소 3개 이상 있고, 순서를 바꿀 수 있는 나머지 0의 개수가 홀수이면 Alice가 유리한 상황 만들 수 있음. 오냐면 항상 Alice가 먼저 돌을 고르면서 3의 배수가 되도록 흐름 만질 수 있음.
        if min(cnt[1], cnt[2]) == 0:
            return max(cnt[1], cnt[2]) > 2 and cnt[0] % 2 > 0
        #나머지 1과 나머지2가 모두 있는 경우
        ## 나머지 1과 나머지 2의 개수 차이가 3이상
        ## 나머지 0의 개수가 짝수여서 Alice가 유리(항상 먼저 시작)
        return abs(cnt[1] - cnt[2]) > 2 or cnt[0] % 2 == 0 

##-------------[나의 풀이] : 실패. 보니까 최적화해서 게임을 끝내는 경우라고 볼 수 없음. (mod_1, mod_3) 또는 (mod_2, mod_3) 중 하나를 뽑을 때 randomness가 들어가기 때문-------------------------------------
"""아이디어
    0) mod_1, mod_2, mod_3 집합을 만든다.
        turn = 0 (turn이 홀수면 Alice 차례, 짝수면 Bob 차례)
    1) current_sum %3 == 1 -> mod_1, mod_3에서 추출
    2) current_sum %3 == 2 -> mod_2, mod_3에서 추출
    1~2 과정을 stone이 1개 이상 있는 동안 반복.
        - 중간에 current_sum %3 == 0 -> 해당 turn에 게임중인 사람이 Alice면 False / Bob이면 True
    stone이 모두 없어지면 return False (bob win)
"""

"""수도코드
    1) mod_1, mod_2, mod_3 집합을 만든다.
        - 전체 stones에 대해 for loop을 돌면서.
    2) remaining_stones 초기화 : len(stones)
        turn 초기화 : 0
        current_sum 초기화 : 0
    3) 게임시작
        - WHILE remaining_stones >= 1 :
            -- IF current_sum %3 == 0 :
                -- IF turn%2 == 1 : RETURN TRUE (Alice 승리)
                -- ELSE : RETURN FALSE (Bob 승리)
            -- turn += 1
            -- IF current_sum %3 == 1 :
                -- 이번에 추출한 돌 cur_stone (mod_1 또는 mod_3에서 꺼냄)
                -- IF mod_3이 비어있지 않으면 거기서 하나 꺼냄. : 
                -- ELSE IF (mod_3이 비어있으면) mod_1에서 하나 꺼냄 :
                -- 만약 mod_3과 mod_1이 모두 비어있다면 :
                    -- mod_2에서 하나 뽑음. 그럼 그  차례의 사람이 짐.
                -- current_sum += cur_stone
                -- remainint_stones -= 1

            -- ELSE IF current_sum %3 == 2 :
                -- 이번에 추출한 돌 cur_stone (mod_2 또는 mod_3에서 꺼냄)
                -- IF mod_3이 비어있지 않으면 거기서 하나 꺼냄. : 
                -- ELSE IF (mod_3이 비어있으면) mod_2에서 하나 꺼냄 :
                -- 만약 mod_3과 mod_2이 모두 비어있다면 :
                    -- mod_1에서 하나 뽑음. 그럼 그  차례의 사람이 짐.
                -- current_sum += cur_stone
                -- remainint_stones -= 1

        - RETURN False (stone이 없어서 Bob이 이기는 경우)
"""

def getStone(stone_list1, stone_list2):
    stone_got = -1
    if len(stone_list1) == 0 and len(stone_list2)== 0:
        return stone_got  #둘다 비어있는 경우
    elif len(stone_list2) == 0 and len(stone_list1) > 0:
        stone_got = stone_list1.pop()
    elif len(stone_list1) == 0 and len(stone_list2) > 0:
        stone_got = stone_list2.pop()
    elif len(stone_list1) >= len(stone_list2):
        stone_got = stone_list1.pop()
    elif len(stone_list2) > len(stone_list1):
        stone_got = stone_list2.pop()
    
    return stone_got


def stoneGameIX(stones):
    mod_1 = []
    mod_2 = []
    mod_3 = []
    for stone in stones:
        if stone %3 == 1 :
            mod_1.append(stone)
        elif stone%3 == 2:
            mod_2.append(stone)
        else :
            mod_3.append(stone)
    
    remaining_stones = len(stones)
    turn = 0
    current_sum = 0

    while remaining_stones >= 1:
        # if current_sum > 0 and current_sum %3 == 0 :
        #     return True if turn%2 == 0 else False
        print("before", remaining_stones, turn, current_sum)
        turn += 1
        if current_sum == 0:
            cur_stone = getStone(mod_1, mod_2)
            if cur_stone == -1 : 
                #cur_stone = mod_3[0]
                return False
            current_sum += cur_stone
            remaining_stones-=1
        elif current_sum %3 == 1 :
            cur_stone = getStone(mod_1, mod_3)
            if cur_stone == -1 : 
                #cur_stone = mod_2[0]
                return True if turn%2 == 0 else False
            current_sum += cur_stone
            remaining_stones -= 1
        elif current_sum %3 == 2 :
            cur_stone = getStone(mod_2, mod_3)
            if cur_stone == -1 : 
                #cur_stone = mod_1[0]
                return True if turn%2 == 0 else False
            current_sum += cur_stone
            remaining_stones -= 1
                    
    return False

#stones = [5,1,2,4,3] #false
#stones = [2] #false
#stones = [2,1] #true
#stones = [2,3] #false
#stones = [20,3,20,17,2,12,15,17,4] # true
stones = [19,2,17,20,7,17] #true

print(stoneGameIX(stones))
# %%
nodes = [1,2,3,4,5]
print(nodes.pop())
# %%
