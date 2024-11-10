# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
class Stack:
    def __init__(self):
        self.items=[]
    def push(self,ele):
        self.items.append(ele)
    def is_empty(self):
        return len(self.items)==0
    def pop(self):
        if self.is_empty():
            return -1
        return self.items.pop()
    def top(self):
        if self.is_empty():
            return -1
        return self.items[-1]
    def size(self):
        return len(self.items)
    def __str__(self):
        if self.is_empty():
            return "Stack is empty."
        print(self.items)

def solution(S):
    # Implement your solution here
    mp = {'}':'{',']':'[',')':'('}
    stack = Stack()
    for ele in S:
        if stack.is_empty():
            stack.push(ele)
            continue
        curr = stack.top()
        if ele in mp and mp[ele]==curr:
            stack.pop()
        else:
            stack.push(ele)
    #print(stack)
    if stack.is_empty():
        return 1
    return 0