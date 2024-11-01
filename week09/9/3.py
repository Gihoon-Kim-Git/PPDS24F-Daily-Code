class Solution(object):
    def maxDepth(self, root):
        if not root:
            return 0

        def dfs(v):
            if not v.children:
                return 1
            else:
                m = 0
                for w in v.children:
                    d = dfs(w)
                    if d > m:
                        m = d
                return m + 1

        return dfs(root)