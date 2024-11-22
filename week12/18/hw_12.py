#1. Sort characters by frequency
class Solution:
    def frequencySort(self, s: str) -> str:
        dct = dict()
        ans = ""
        lst = []
        for st in s:
            if st not in dct.keys():
                dct[st] = s.count(st)
        
        sorted_dct = sorted(dct.items(), key=lambda item: item[1], reverse = True)
        for num in sorted_dct:
            ans += num[0]*num[1]

        return ans
        



#2. Largest number
def compare(x, y):
    return x+y > y+x

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        ans = ""
        str_nums = list(map(str, nums))

        for i in range(len(str_nums)):
            for j in range(len(str_nums)-1):
                if not compare(str_nums[j], str_nums[j+1]):
                    str_nums[j], str_nums[j+1] = str_nums[j+1], str_nums[j]
        
        largest_num = ''.join(str_nums)

        return '0' if largest_num[0] == '0' else largest_num



#3. Battleships in a board
def dfs(i, j, visited, board, cnt):
    visited[i][j] = True

    if (j+1 < len(board[0])) and (0 <= i) and (i < len(board)):
        if board[i][j+1] == 'X' and visited[i][j+1] == False:
            dfs(i, j+1, visited, board, cnt)

    if (j > 0) and (0 <= i) and (i < len(board)):
        if board[i][j-1] == 'X' and visited[i][j-1] == False:
            dfs(i, j+1, visited, board, cnt)
    
    if (i+1 < len(board)) and (0 <= j) and (j < len(board[i])):
        if board[i+1][j] == 'X' and visited[i+1][j] == False:
            dfs(i+1, j, visited, board, cnt)
    
    if (i > 0) and (0 <= j) and (j < len(board[i])):
        if board[i-1][j] == 'X' and visited[i-1][j] == False:
            dfs(i-1, j, visited, board, cnt)
            
            
            
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        visited = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
        cnt = [0]
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'X' and visited[i][j] == False:
                    dfs(i, j, visited, board, cnt[0])
                    cnt[0] += 1
        
        return cnt[0]




#4. Implement queue using stacks
class MyQueue:

    def __init__(self):
        self.inbox = list()
        self.outbox = list()
        
    def push(self, x: int) -> None:
        self.inbox.append(x)        

    def pop(self) -> int:
        if not self.outbox:
            while self.inbox:
                self.outbox.append(self.inbox.pop())
        return self.outbox.pop()


    def peek(self) -> int:
        if not self.outbox:
            while self.inbox:
                self.outbox.append(self.inbox.pop())
        return self.outbox[-1]  # Peek the front element from the outbox

    def empty(self) -> bool:
        return len(self.inbox) == 0 and len(self.outbox) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()



#5. Implement stack using queues
from queue import Queue

class MyStack:

    def __init__(self):
        self.main = Queue()
        self.sub = Queue()

    def push(self, x: int) -> None:
        self.main.put(x)

    def pop(self) -> int:
        if self.main.empty():
            return

        while self.main.qsize() != 1:  # 메인 큐가 1개 남을 때까지 임시 큐에 넣기
            self.sub.put(self.main.get())

        result = self.main.get()

        self.main, self.sub = self.sub, self.main  # swap
        return result

    def top(self) -> int:
        while self.main.qsize() > 1:
            self.sub.put(self.main.get())

        # Get the last element, which is the top of the stack
        result = self.main.get()

        # Push the top element back into the sub queue
        self.sub.put(result)

        # Swap main and sub queues
        self.main, self.sub = self.sub, self.main
        return result
    
    
    def empty(self) -> bool:
        return self.main.empty()


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()