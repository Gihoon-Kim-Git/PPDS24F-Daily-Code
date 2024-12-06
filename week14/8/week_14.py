#1. Integer to Roman
class Solution:
    def intToRoman(self, num: int) -> str:
        dct = {1000: "M", 900: "CM", 500:"D", 400:"CD", 100:"C", 90 :"XC", 50:"L", 40:"XL", 10:"X", 9:"IX", 5:"V", 4:"IV", 1:"I"}

        r = ""
        for i in range(13):
            q = num//list(dct.keys())[i]
            for j in range(q):
                r += list(dct.values())[i]
            num -= q*list(dct.keys())[i]

        return r




#2. Swap Nodes in Pairs
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head

        slow = head
        fast = head.next
        new_head = fast
        curr = None

        while fast:
            slow.next = fast.next
            fast.next = slow

            if curr:
                curr.next = fast
            
            curr = slow

            slow = slow.next
            
            if slow:
                fast = slow.next
            else:
                fast = None

        return new_head




#3. Next Greater Element 1
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = [-1 for _ in range(len(nums1))]

        for i in range(len(nums1)):
            if nums1[i] == nums2[len(nums2)-1]:
                ans[i] = -1

            for j in range(len(nums2)):
                if nums1[i] == nums2[j]:
                    k = j+1
                    while k < len(nums2):
                        if nums1[i] < nums2[k]:
                            ans[i] = nums2[k]
                            break
                        k+=1
                    if k == len(nums2):
                        ans[i] = -1
        
        return ans






#4. Minesweeper
class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        # Get the row and column of the click
        i,j = click[0],click[1]
        
        # If the click is on a mine, change it to 'X' and return the board
        if board[i][j] == 'M':
            board[i][j] = 'X'
            return board
        
        # Get the dimensions of the board
        m,n = len(board),len(board[0])
        
        # Initialize a stack with the click position
        st = [(i,j)]
        
        # Define the directions for checking adjacent cells
        dirs = [(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]
        
        # While the stack is not empty
        while st:
            # Pop a cell from the stack
            x,y = st.pop()
            
            # If the cell is empty
            if board[x][y] == 'E':
                # Count the number of mines in adjacent cells
                cnt = 0
                for dx,dy in dirs:
                    new_x, new_y = x+dx, y+dy
                    if 0<=new_x<m and 0<=new_y<n and board[new_x][new_y] == 'M':
                        cnt += 1
                
                # If there are no mines in adjacent cells
                if cnt == 0:
                    # Change the cell to 'B'
                    board[x][y] = 'B'
                    
                    # Add all adjacent cells to the stack
                    for dx,dy in dirs:
                        new_x, new_y = x+dx, y+dy
                        if 0<=new_x<m and 0<=new_y<n:
                            st.append((new_x,new_y))
                else:
                    # Change the cell to the number of mines in adjacent cells
                    board[x][y] = str(cnt)
        
        # Return the updated board
        return boardd




#5. Pancake Sorting
from typing import List

class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        lst = []  # 연산 결과를 담을 리스트
        
        # 배열을 하나씩 처리하면서 큰 값들을 정렬
        for i in range(len(arr), 1, -1):
            # 현재 값 i의 위치를 찾음
            index = arr.index(i)
            
            # i가 이미 올바른 위치에 있지 않으면
            if index != i - 1:
                # i가 배열의 맨 앞에 있지 않으면, 먼저 맨 앞으로 가져옴
                if index != 0:
                    lst.append(index + 1)  # 배열의 처음부터 index까지 뒤집는 연산
                    arr[:index + 1] = arr[:index + 1][::-1]  # index까지 역순으로 뒤집음
                
                # 이제 i를 배열의 올바른 위치로 옮기기 위해 전체 배열을 뒤집음
                lst.append(i)  # 배열의 처음부터 i까지 뒤집는 연산
                arr[:i] = arr[:i][::-1]  # i까지 역순으로 뒤집음

        return lst  # 수행한 연산을 반환




