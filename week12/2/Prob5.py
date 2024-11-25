from collections import deque

class MyStack:

    def __init__(self):
        # 두 개의 queue를 사용하여 stack을 구현
        self.queue1 = deque()
        self.queue2 = deque()

    def push(self, x: int) -> None:
        # 새로운 원소를 queue1에 추가
        self.queue1.append(x)

    def pop(self) -> int:
        # queue1에 있는 모든 원소를 하나씩 queue2로 옮김(마지막 원소는 제외)
        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())
        # queue1의 마지막 원소를 제거하고 그 값을 반환(스택의 top 원소)
        res = self.queue1.popleft()
        # queue1과 queue2를 교환하여 queue1이 항상 데이터를 가지도록 조치
        self.queue1, self.queue2 = self.queue2, self.queue1
        return res

    def top(self) -> int:
        # pop과 동일하게 동작하지만 마지막 원소를 제거하지 않고 반환
        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())
        res = self.queue1.popleft()
        self.queue2.append(res)  # 마지막 원소를 다시 queue2로 옮김
        self.queue1, self.queue2 = self.queue2, self.queue1
        return res

    def empty(self) -> bool:
        # 데이터를 보관하는 목적인 queue1이 비어 있는지 확인하는 것만으로 가능
        return not self.queue1
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()



input = ["MyStack","push","push","top","pop","empty"]
inputval = [[],[1],[2],[],[],[]]

result = []

# 테스트 환경 구현, output check 용도
for i in range(len(input)):
    #print(i, input[i], inputval[i])
    if input[i] == "MyStack":
        obj = MyStack()
        result.append(None)
    elif input[i] == "push":
        obj.push(inputval[i][0])
        result.append(None)
    elif input[i] == "top":
        result.append(obj.top())
    elif input[i] == "pop":
        result.append(obj.pop())
    elif input[i] == "empty":
        result.append(obj.empty())

print(result)