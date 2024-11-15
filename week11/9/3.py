import heapq
def minCostConnectPoints(points):

    n = len(points)
    if n==1: return 0

    # Prim's algorithm (greedy)
    min_cost = 0
    min_heap = [(0,0)]    # (cost, node index)
    visited = set()
    edges = 0

    while edges < n:
        cost, i = heapq.heappop(min_heap)     # 이전 노드에서 연결하는 cost가 가장 적은 애들부터 pop 됨
        if i in visited:
            continue
        min_cost += cost
        visited.add(i)
        edges += 1

        for j in range(n):
            if j not in visited:
                manhattan_distance = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])
                heapq.heappush(min_heap, (manhattan_distance,j))

    return min_cost