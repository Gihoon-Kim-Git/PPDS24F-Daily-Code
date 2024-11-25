#%%
from collection import deque
class MyStack:

    def __init__(self):
        #큐2는 비어있고, 실제 값들은 queue1에 다 저장
        self.queue1 = deque()
        self.queue2 = deque()

    def push(self, x: int) -> None:
        self.queue1.append(x)

    def pop(self) -> int:
        # queue1의 마지막 요소를 제외하고 모두 queue2로 이동
        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())
        # 마지막 요소가 스택의 top, pop 대상
        result = self.queue1.popleft()
        # queue1과 queue2 교체
        self.queue1, self.queue2 = self.queue2, self.queue1
        return result

    def top(self) -> int:
        # queue1의 마지막 요소를 제외하고 모두 queue2로 이동
        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())
        # 마지막 요소를 반환하되 제거하지 않음
        result = self.queue1.popleft()
        self.queue2.append(result)  # 다시 queue2로 넣음
        # queue1과 queue2 역할 교환
        self.queue1, self.queue2 = self.queue2, self.queue1
        return result
        
    def empty(self) -> bool:
        return not self.queue1
        

        