from typing import List

class UnionFind:
    def __init__(self, n):
        # 초기화: 각 노드를 그 자신이 부모로 설정하여 n개의 독립적인 집합으로 만듦
        self.parent = list(range(n))

    def find(self, u):
        # 경로 압축(Path Compression) 기법: 노드 u의 루트 노드를 찾음
        if u != self.parent[u]:
            self.parent[u] = self.find(self.parent[u])  # 부모를 루트로 업데이트하여 경로 압축
        return self.parent[u]  # 루트 노드를 반환

    def union(self, u, v):
        # 두 집합을 합침(Union): u와 v가 속한 집합을 하나로 합침
        pu = self.find(u)  # u의 루트 찾기
        pv = self.find(v)  # v의 루트 찾기
        if pu == pv: return False  # u와 v가 이미 같은 집합에 속해 있다면 False 반환
        self.parent[pu] = pv  # 하나의 집합으로 합침: u의 루트를 v의 루트로 설정
        return True  # 합집합이 성공했음을 표시하기 위해 True 반환


class Solution:
    # 두 점 간의 맨해튼 거리를 계산하는 함수
    def manhattanDist(self, p1, p2):
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        edges = []  # 간선 리스트 초기화
        n = len(points)  # 점의 개수

        # 모든 점 쌍에 대해 간선 생성
        for i in range(n):
            for j in range(i+1, n):
                dist = self.manhattanDist(points[i], points[j])  # 두 점 간의 거리 계산
                edges.append([dist, i, j])  # 간선 리스트에 (거리, 점1, 점2) 추가

        return self.kruskalMST(edges, n)  # Kruskal's Algorithm을 사용해 MST 비용 계산

    def kruskalMST(self, edges, n):
        edges.sort()  # 간선 리스트를 거리(dist) 기준으로 오름차순 정렬
        uf = UnionFind(n)  # Union-Find 자료구조 초기화
        mstDist = 0  # MST의 총 비용을 저장할 변수 초기화
        mstEdgeSize = 0  # MST에 포함된 간선의 수를 기록할 변수 초기화

        for w, u, v in edges:
            if uf.union(u, v):  # 두 점이 서로 다른 집합에 속해 있다면(=union 성공)
                mstDist += w  # 해당 간선의 비용을 MST 비용에 추가
                mstEdgeSize += 1  # MST에 포함된 간선 수 증가
            
            if mstEdgeSize == n - 1:  # MST에 정확히 n-1개의 간선이 포함되면 종료
                return mstDist  # MST의 총 비용 반환

        return 0  # 간선이 없는 경우(단일 점), 비용은 0