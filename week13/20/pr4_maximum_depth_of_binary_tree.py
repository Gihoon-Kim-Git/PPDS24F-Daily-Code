#이런 유형은 C로도 풀 수 있다.
from collections import deque

s = deque([['abc',1]])
x,y = s.pop()
print(x,y)
s.append(['bcd',2])
x,y = s.pop()
print(x,y)