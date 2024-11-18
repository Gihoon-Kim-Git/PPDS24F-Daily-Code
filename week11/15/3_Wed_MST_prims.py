import heapq
from typing import List

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        N = len(points)  # 주어진 점(points)들의 개수를 N에 저장

        # 각 정점을 키로, 빈 리스트를 값으로 가지는 인접 리스트(adj) 초기화
        adj = {i:[] for i in range(N)}

        # 모든 점들 간의 거리를 계산하여 인접 리스트에 추가
        for i in range(N):
            x1, y1 = points[i]  # i번째 점의 좌표를 x1, y1에 저장
            
            for j in range(i+1, N):
                x2, y2 = points[j]  # j번째 점의 좌표를 x2, y2에 저장
                dist = abs(x1-x2) + abs(y1-y2)  # 두 점 사이의 맨해튼 거리 계산
                
                adj[i].append((dist, j))  # i번 정점에서 j번 정점으로 가는 간선 추가
                adj[j].append((dist, i))  # j번 정점에서 i번 정점으로 가는 간선 추가

        ans = 0  # 최소 비용을 저장할 변수 초기화
        visited = set()  # 이미 방문한 정점을 기록할 집합 초기화
        cost_idx = [(0, 0)]  # 시작 정점 (0번 정점)과 비용 0을 우선순위 큐에 추가

        # 모든 정점을 방문할 때까지 반복
        while len(visited) < N:
            cost, idx = heapq.heappop(cost_idx)  # 우선순위 큐에서 가장 낮은 비용의 정점 선택
            if idx in visited:  # 이미 방문한 정점이라면 건너뜀
                continue
            
            visited.add(idx)  # 선택한 정점을 방문 처리
            ans += cost  # 선택한 간선의 비용을 총 비용에 더함
            
            # 선택한 정점과 인접한 정점들을 탐색
            for nei in adj[idx]:
                if nei[1] not in visited:  # 인접한 정점이 아직 방문되지 않았다면
                    heapq.heappush(cost_idx, nei)  # 해당 정점과 간선을 우선순위 큐에 추가

        return ans  # 최소 비용 반환
