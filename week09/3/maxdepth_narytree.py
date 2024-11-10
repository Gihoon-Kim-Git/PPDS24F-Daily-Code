# Problem Summary:
# Given an n-ary tree, we need to find its maximum depth.
# The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
# N-ary Tree input serialization is represented in level order traversal, where each group of children is separated by the null value.
#
# Example 1:
# Input: root = [1, null, 3, 2, 4, null, 5, 6]
# Output: 3
# Explanation: The maximum depth is 3 because the longest path from the root node (1) to the farthest leaf nodes (5 or 6) consists of 3 nodes.
#
# Example 2:
# Input: root = [1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null, 9, 10, null, null, 11, null, 12, null, 13, null, null, 14]
# Output: 5
# Explanation: The maximum depth is 5.

# Constraints:
# - The total number of nodes is in the range [0, 10^4].
# - The depth of the n-ary tree is less than or equal to 1000.

from typing import List, Optional

# Definition for a Node
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children

# SOLUTION FOUND IN LEETCODE!
def maxDepth(root: 'Node') -> int:
    if root is None: # tree is empty
        return 0
    
    # helper function: Depth-First Search
    # node: the current node being processed
    # depth: the current depth of this node in the tree
    def dfs(node, depth):
        # current node has no children (leaf node)
        if not node.children:
            return depth
        
        # node has children: perform DFS on each child
        # max(): returns maximum depth among all children
        # recursive call of the dfs function: add 1 to the depth as going 1 level deeper for each child
        return max(dfs(child, depth+1) for child in node.children)
    
    # start DFS traversal from the root node with an initial depth of 1
    return dfs(root, 1)

# Time Complexity: O(n), where n is the total number of nodes in the tree. We visit each node exactly once
# Space Complexity: O(h), where h is the height of the tree. This space is used by the recursion stack

if __name__ == "__main__":
    # Example 1
    # Creating the n-ary tree with the structure:
    #           1
    #         / | \
    #        3  2  4
    #       / \
    #      5   6
    # Expected output: 3
    child5 = Node(5)
    child6 = Node(6)
    child3 = Node(3, [child5, child6])
    child2 = Node(2)
    child4 = Node(4)
    root1 = Node(1, [child3, child2, child4])

    # Finding the maximum depth
    print("Maximum Depth of Tree 1:", maxDepth(root1))  # Output: 3

    # Example 2 (more complex tree)
    # Creating a more complex n-ary tree with a depth of 5
    # Tree structure:
    #           1
    #      /    |    \
    #     2     3     4
    #    / \   / \    |
    #   6   7 11 12  14
    #       |     |
    #       8    13
    #      / \
    #     9  10
    # Expected output: 5
    child14 = Node(14)
    child13 = Node(13)
    child12 = Node(12, [child13])
    child11 = Node(11)
    child10 = Node(10)
    child9 = Node(9)
    child8 = Node(8, [child9, child10])
    child7 = Node(7, [child8])
    child6 = Node(6)
    child5 = Node(5)
    child4 = Node(4, [child14])
    child3 = Node(3, [child11, child12])
    child2 = Node(2, [child6, child7])
    root2 = Node(1, [child2, child3, child4])

    # Finding the maximum depth
    print("Maximum Depth of Tree 2:", maxDepth(root2))  # Output: 5

    # Additional Test Case
    # Single node tree
    # Tree structure:
    #     1
    # Expected output: 1
    single_node_root = Node(1)
    print("Maximum Depth of Single Node Tree:", maxDepth(single_node_root))  # Output: 1

    # Edge Case: Empty tree (root is None)
    # Expected output: 0
    print("Maximum Depth of Empty Tree:", maxDepth(None))  # Output: 0

"""
$ python maxdepth_narytree.py
Maximum Depth of Tree 1: 3
Maximum Depth of Tree 2: 5
Maximum Depth of Single Node Tree: 1
Maximum Depth of Empty Tree: 0
"""