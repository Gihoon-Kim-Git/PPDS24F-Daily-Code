"""문제
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
"""
"""풀이방법
    1. 현재위치 cur에서의 maxdepth는 max(cur_left의 maxdepth, cur_right의 maxdepth)+1
    2. maxdepth(cur)
        만약에 cur이 자식 하나도 없으면 return 1  
        (이거보다, cur==None이면 return 0 하는 게 더 범용적임.)
        자식이 있으면 maxdepth(child) 값 중 max값 + 1 
"""

# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
        
def maxDepth(self, root:Node)->int:
    if root == None: # 이 조건 필수. 이 조건 없이 if root.children == [] 있으면 root가 None일때 root.children 접근 못해서 error발생.
        return 0
    # if root.children == []: 이 조건은 위 if root == None으로 대체 가능.
    #     return 1
    else :
        max_depth_of_child = 0
        for child in root.children :
            cur_depth = maxDepth(child)
            if max_depth_of_child < cur_depth:
                max_depth_of_child = cur_depth
        return max_depth_of_child + 1
                
        
# 다른 방법 : BFS활용. queue를 넣을때 (node, cur_level+1) 로 tuple 활용