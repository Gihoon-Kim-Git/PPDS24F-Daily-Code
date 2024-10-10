def sumOfLeftLeaves(root):
    def dft(node):
        if node is None:
            return 0
        sum = 0
        if node.left and node.left.left is None and node.left.right is None:  # 자식 없을 때
            sum += node.left.val
        sum += dft(node.left)
        sum += dft(node.right)

        return sum
    
    result = dft(root)
        
    return result
