class MyQueue:

    def __init__(self):
        self.start = []  # 입력용 스택
        self.end = []    # 출력용 스택

    def push(self, x: int) -> None:
        # 새 값을 start 스택에 추가
        self.start.append(x)

    def pop(self) -> int:
        # pop이나 peek이 실행될때마다 거꾸로 순서해서 넣어주는거임.
        # 어차피 end가 안비어있으면 다시 안 넣으므로 end에는 무조건 가장 먼저 넣은게 가장 바깥쪽에 들어가있는 구조일거임
        # 그렇게 해야 end 끝에서 하나씩 빼면 queue처럼 가장 먼저 넣은게 가장 먼저 나옴!
        # end 스택이 비어 있다면 다시 start의 값을 거꾸로 end로 넣기
        if not self.end:
            while self.start:
                self.end.append(self.start.pop())
        # end 스택에서 값을 제거하여 반환
        return self.end.pop()

    def peek(self) -> int:
        if not self.end:
            while self.start:
                self.end.append(self.start.pop())
        return self.end[-1]

    def empty(self) -> bool:
        # 두 스택이 모두 비어 있으면 큐는 비어 있음
        return not self.start and not self.end