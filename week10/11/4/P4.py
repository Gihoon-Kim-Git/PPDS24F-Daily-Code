#%%
### 최종 optimize된 버전(w/o ChatGPT)
class ExamRoom:
    def __init__(self, n: int):
        # 전체 좌석 사이즈 n과 앉은 자리 인덱스를 저장하는 리스트
        self.seated = []
        self.size = n

    def seat(self) -> int:
        # 가장 처음 넣을 땐, 0번에 넣는다
        if len(self.seated) == 0:
            self.seated.append(0)
            return 0
        
        if len(self.seated) == 1:
            if self.seated[0] > self.size//2:
                self.seated.append(0)
                self.seated = sorted(self.seated)
                return 0
            else:
                self.seated.append(self.size - 1)
                return self.size - 1
            
        # 가장 큰 차이, 시작 인덱스 초기화
        max_dif = 0
        max_ind = 0

        # 첫 시작 시 0이 있으면 똑같이, 0이 없으면 2로 나누지 않기
        if 0 not in self.seated:
            #이 경우 ind를 -1로 둬서 그냥 0과 구분
            max_ind = -1
            max_dif = self.seated[0]
        else:
            max_ind = 0
            max_dif = (self.seated[1] - self.seated[0])//2
            
        # 1번째 인덱스부터 seat.size - 2번째까지 돌면서 가장 큰 차이 탐색
        for i in range(1, len(self.seated)-1):
            cur_dif = (self.seated[i+1] - self.seated[i])//2
            if cur_dif > max_dif:
                max_dif = cur_dif
                max_ind = self.seated[i]

        # 마지막 인덱스에 self.size - 1 있는지 체크 
        # 없으면 n-1에서 self.seated[-1]을 뺀 값과 max_dif 비교
        if self.size-1 not in self.seated:
            cur_dif = self.size - 1 - self.seated[-1]
            if cur_dif > max_dif:
                #만약 이 값이 더 크다면 맨 마지막에 들어가야 하므로 바로 추가 후 종료
                self.seated.append(self.size-1)
                self.seated = sorted(self.seated)
                return self.size-1
            
        # 마지막 인덱스에 n-1이 있는 경우    
        else:
            cur_dif = (self.seated[len(self.seated) - 2] - self.seated[len(self.seated) - 1])//2
            if cur_dif > max_dif:
                max_dif = cur_dif
                max_ind = self.seated[len(self.seated) - 2]
        
        # max_ind가 -1이면 0에 넣기
        if max_ind == -1:
            self.seated.append(0)
            self.seated = sorted(self.seated)
            return 0

        # 위 경우(처음에 넣거나 끝에 넣는 경우)가 아니라면 중간에 있는 경우
        # max_ind에 max_dif를 더한 곳에 넣는다
        self.seated.append(max_ind + max_dif)
        self.seated = sorted(self.seated)
        return max_ind + max_dif


    def leave(self, p: int) -> None:
        self.seated = [x for x in self.seated if x != p]

#%%
### Leetcode는 accept 
# 하지만, [-1,5,13,14]와 같은 경우에 제대로 작동 안함
class ExamRoom:
    def __init__(self, n: int):
        #처음과 끝 처리를 위해 -1과 size를 넣은 상태로 시작
        self.seated = [-1, n]
        self.size = n

    def seat(self) -> int:
        # 가장 처음 넣을 땐, 0번에 넣는다
        if len(self.seated) == 2:
            self.seated.append(0)
            self.seated = sorted(self.seated)
            return 0
    
        # 가장 큰 차이, 시작 인덱스 초기화
        max_dif = 0
        max_ind = 0

        # 가장 마지막 인덱스 전까지 돌면서 가장 큰 차이 탐색
        for i in range(len(self.seated)-1):
            cur_dif = (self.seated[i+1] - self.seated[i])//2
            if cur_dif > max_dif:
                max_dif = cur_dif
                max_ind = self.seated[i]

        # 마지막에서 2번째 인덱스에 self.size - 1 없으면 마지막에 없는 것이므로 
        # 최대 인덱스에서 직전을 뺀 값과 max_dif 비교
        if self.size-1 not in self.seated:
            cur_dif = self.size - 1 - self.seated[-2]
            if cur_dif > max_dif:
                self.seated.append(self.size-1)
                self.seated = sorted(self.seated)
                return self.size-1
        
        # max_ind가 -1이면 처음 부분이 시작하는 부분에 넣기
        if max_ind == -1:
            self.seated.append(0)
            self.seated = sorted(self.seated)
            return 0

        # 위 경우가 아니라면 중간에 있는 경우
        # 그냥 시작 인덱스에 최대 차이를 더한 곳에 넣는다
        self.seated.append(max_ind + max_dif)
        self.seated = sorted(self.seated)
        return max_ind + max_dif


    def leave(self, p: int) -> None:
        self.seated = [x for x in self.seated if x != p]



#%%
### 두 번째 시도였고, 로직은 맞으나 Timeout...
class ExamRoom:

    def __init__(self, n: int):
        self.room = [0 for _ in range(n)]
        self.size = n

    def seat(self) -> int:
        if 1 not in self.room:
            self.room[0] = 1
            return 0
        
        if 1 not in self.room[1:]:
            self.room[-1] = 1
            return self.size-1
        
        if 1 not in self.room[1:-1]:
            self.room[(self.size-1) // 2] = 1
            return (self.size-1) // 2
        
        m_dis = 0
        m_ind = 0
        for i in range(self.size):
            if self.room[i] == 0:
                l, r = i, i

                while l > 0 and self.room[l] == 0:
                    l -= 1
                while r < self.size-1 and self.room[r] == 0:
                    r += 1
                dis = min(r-i, i-l)
                
                if m_dis < dis:
                    m_dis = dis
                    m_ind = i
        self.room[m_ind] = 1
        return m_ind

    def leave(self, p: int) -> None:
        self.room[p] = 0



#%%
c = ExamRoom(10)

print(c.seat())
print(c.seat())
print(c.seat())
print(c.seat())
print(c.leave(4))
print(c.seat())
#%%
s = ExamRoom(14)
s.seat()
s.seat()
s.seat()
s.seat()
s.seat()
s.seat()
s.seat()
s.seat()
s.seat()
s.seat()
s.seat()
s.seat()
s.seat()
s.seat()
s.leave(0)
s.leave(1)
s.leave(2)
s.leave(3)
s.leave(4)
s.leave(6)
s.leave(7)
s.leave(8)
s.leave(9)
s.leave(10)
s.leave(11)
s.leave(12)
print(s.seated)
print(s.seat())

# %%
### 첫시도 였던 것...
### 로직 불완전
class ExamRoom:
    def seat2(self) -> int:
        if 1 not in self.room:
            self.room[0] = 1
            return 0
        
        # 가장 거리가 긴 두 점 찾기
        mds = 0
        mde = 0
        for u in range(self.size):
            if self.room[u] == 1:
                dis = u
                mds = 0
                mde = u
                break
        flag = 0
        i = 0
        while i < self.size-1:
            if self.room[i] == 1:
                for j in range(i+1,self.size):
                    if self.room[j] == 1:
                        if (j - i)//2 > dis:
                            print(i,j)
                            mds = i
                            mde = j
                            dis = (j - i)//2
                            flag = 1
                        i = j
            i += 1
        
        # 만약 1을 두개 못 찾았을 때
        unione = 0
        if flag == 0:
            for k in range(self.size):
                if self.room[k] == 1:
                    unione = k
                    break
            if unione <= self.size//2:
                self.room[-1] = 1
                return self.size - 1
            else: 
                self.room[0] = 1
                return 0

        self.room[(mds + mde) // 2] = 1
        return (mds + mde) // 2
    ###