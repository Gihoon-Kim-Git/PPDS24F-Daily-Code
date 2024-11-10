class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        vertices, adj = self.board_to_adj(board)
        result = False
        for source in vertices:
            result = result or self.dfs_helper(source, vertices, adj, 0, word, [])
            if result:
                break
        return result

    def dfs_helper(self, curr: int, vertices: dict[int, str], adj: dict[int, list[int]], level: int, word: str, visited: list[int]):
        # print(f"[Level {level} in {word}], curr : {vertices[curr]}({curr})")
        # base case
        # - 불일치
        if vertices[curr] != word[level]:
            # print("BACKTRACKING!")
            return False
        # - 일치 & 끝까지 도달
        elif level == len(word) - 1:
            # print(f"[{level}] {curr} : {vertices[curr]} / {word[level]}")
            return True

        # recursive case
        # - 일치 & 아직 끝까지 도달하지 못함
        else:
            result = False
            for neighbor in adj[curr]:
                if neighbor not in visited:
                    this_result = self.dfs_helper(neighbor, vertices, adj, level+1, word, visited+[curr])
                    # if this_result:
                    #     print(f"[{level}] {neighbor} : {vertices[neighbor]} / {word[level]}")
                    # print()
                    result = result or this_result
                if result: break
            return result

    def board_to_adj(self, board: list[list[str]]) -> tuple[dict[int, str], dict[int, list[int]]]:
        directions = [
                    [-1, 0],
            [0, -1],         [0, 1],
                    [1, 0]
        ]

        vertices = dict()
        adj = dict()

        M = len(board)
        N = len(board[0])

        for i in range(M):
            for j in range(N):
                node = i * N + j
                vertices[node] = board[i][j]
                adj[node] = []
                for d in directions:
                    ii = i + d[0]
                    jj = j + d[1]
                    if 0 <= ii < M and 0 <= jj < N:
                        neighbor = ii * N + jj
                        adj[node].append(neighbor)
        
        return vertices, adj
