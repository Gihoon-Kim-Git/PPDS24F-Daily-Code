def maxDepth(root):
    queue = []
    if root:
        queue += [(root,1)]
    maxDepth = 0
    while queue:
        (node,depth) = queue.pop(0)
        maxDepth = depth
        queue += ((child, depth+1) for child in node.children)

    return maxDepth



root1 = [1,None,3,2,4,None,5,6]
root2 = [1,None,2,3,4,5,None,None,6,7,None,8,None,9,10,None,None,11,None,12,None,13,None,None,14]
print("Maximum Depth:", maxDepth(root1))  # 3
print("Maximum Depth:", maxDepth(root2))  # 5




