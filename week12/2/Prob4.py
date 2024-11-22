class MyQueue:

    def __init__(self):
        # 스택 두 개를 활용하여 queue를 구현 
        self.stack_in = []  # 입력 스택 (push 용도)
        self.stack_out = []  # 출력 스택 (pop, peek 용도)

    def push(self, x: int) -> None:
        self.stack_in.append(x)

    def pop(self) -> int:
        # 출력 스택이 비어 있다면, 입력 스택의 모든 요소를 옮겨 담음
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())
        # 출력 스택의 맨 위 요소를 반환: FIFO 순서를 유지
        return self.stack_out.pop()

    def peek(self) -> int:
        # 출력 스택이 비어 있다면, 입력 스택의 모든 요소를 옮겨 담음
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())
        # 출력 스택의 맨 마지막 요소를 반환: 큐의 front 요소
        return self.stack_out[-1]

    def empty(self) -> bool:
        # 입력 스택과 출력 스택이 모두 비어 있으면 큐는 비어있다고 판단
        return not self.stack_in and not self.stack_out
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()


input = ["MyQueue","push","push","peek","pop","empty"]
inputval = [[],[1],[2],[],[],[]]

result = []

# 테스트 환경 구현, output check 용도
for i in range(len(input)):
    #print(i, input[i], inputval[i])
    if input[i] == "MyQueue":
        obj = MyQueue()
        result.append(None)
    elif input[i] == "push":
        obj.push(inputval[i][0])
        result.append(None)
    elif input[i] == "peek":
        result.append(obj.peek())
    elif input[i] == "pop":
        result.append(obj.pop())
    elif input[i] == "empty":
        result.append(obj.empty())

print(result)
