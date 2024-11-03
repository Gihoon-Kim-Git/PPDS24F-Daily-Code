class Solution:
    def isBipartite(self, graph: list[list[int]]) -> bool:
        n = len(graph)
        colors = [-1] * n  # -1로 초기화 (아직 색칠되지 않은 상태)

        def dfs(node: int, color: int) -> bool:
            colors[node] = color  # 현재 노드를 주어진 색으로 색칠
            for neighbor in graph[node]:
                if colors[neighbor] == -1:  # 이웃 노드가 색칠되지 않았다면
                    # 이웃 노드를 반대 색으로 색칠하고 DFS 재귀 호출
                    if not dfs(neighbor, 1 - color):
                        return False
                elif colors[neighbor] == color:  # 이웃 노드가 같은 색으로 칠해져 있다면
                    return False
            return True

        for i in range(n):
            # 아직 색칠되지 않은 노드에 대해 DFS 실행
            if colors[i] == -1:
                if not dfs(i, 0):  # 0부터 시작해서 색칠
                    return False
        return True