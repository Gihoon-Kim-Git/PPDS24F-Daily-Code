#1. valid palindrome
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s = s.replace(" ", "")

        n = ""
        for char in s:
            if((ord(char) >= 97 and ord(char) <= 122) or (ord(char) >= 48 and ord(char) <= 57)):
                n += char

        if n == n[::-1]:
            return True
        else:
            return False



#2. min cost climbing stairs
#define min(x, y) (x) < (y) ? (x) : (y)
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0 for _ in range(n+1)]

        dp[0] = 0
        dp[1] = 0

        for i in range(2, n+1):
            dp[i] = min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1])

        return dp[n]


#3. min cost to connect all points
def dist(a, b):
    return abs(a[0]-b[0]) + abs(a[1]-b[1])

def find(parent, v):
    if v == parent[v]:
        return v
    else:
        parent[v] = find(parent, parent[v])
        return parent[v]

def union(parent, a, b):
    a = find(parent, a)
    b = find(parent, b)

    if a != b:
        parent[a] = b

def MSTKruskal(vertices, edges):
    mst = []

    edges.sort(key=lambda edge : edge[2])

    for edge in edges:
        set1 = find(vertices, edge[0])
        set2 = find(vertices, edge[1])

        if set1 != set2:
            mst.append(edge)
            union(vertices, set1, set2)
    
    return mst


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        vertices = []
        for i in range(len(points)):
            vertices.append(i)
        #[0,1,2,3,4]

        edges = []
        for i in range(len(points)-1):
            for j in range(i+1, len(points)):
                edges.append((i, j, dist(points[i], points[j])))
        #[(0,1,4), (0,2,13), ..., (3,4,4)]

        
        mst = MSTKruskal(vertices, edges)

        totalweight = 0
        for edge in mst:
            totalweight += edge[2]

        return totalweight






#4. longest common prefix
from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:  # Edge case: empty list
            return ""
        
        # Start with the first string as the prefix
        prefix = strs[0]
        
        for string in strs[1:]:
            # Trim the prefix until it matches the start of the current string
            while not string.startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return ""  # No common prefix
        
        return prefix



#5. maximal square
class Solution:
    def maximalSquare(self, matrix):
        if not matrix:
            return 0
        
        m, n = len(matrix), len(matrix[0])
        # DP 배열 초기화
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        max_side = 0  # 가장 큰 정사각형 한 변의 길이를 추적
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if matrix[i-1][j-1] == "1"
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    max_side = max(max_side, dp[i][j])  # 가장 큰 정사각형의 한 변 길이 갱신
        
        # 가장 큰 정사각형의 면적
        return max_side * max_side
