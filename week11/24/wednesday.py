# Min Cost to Connect All Points
from typing import List

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        if len(points) == 0 or len(points) == 1:
            return 0

        val = 0
        connected = [False] * len(points)  # Track connected points
        min_edge = [float('inf')] * len(points)  # Minimum edge cost to connect each point
        min_edge[0] = 0  # Start from the first point

        for _ in range(len(points)):
            # Find the point with the minimum edge cost that is not yet connected
            u = min((cost, idx) for idx, cost in enumerate(min_edge) if not connected[idx])[1]
            val += min_edge[u]  # Add the cost of the edge
            connected[u] = True  # Mark the point as connected
            if all(connected): # Return the total cost to connect all points
                return val

            # Update the minimum edge costs for the connected points
            for v in range(len(points)):
                if not connected[v]:
                    cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1])
                    min_edge[v] = min(min_edge[v], cost)  # Update the minimum edge cost


if __name__ == "__main__":
    sol = Solution()
    print(sol.minCostConnectPoints([[0,0],[2,2],[3,10],[5,2],[7,0]]))
    print(sol.minCostConnectPoints([[3,12],[-2,5],[-4,1]]))
    print(sol.minCostConnectPoints([[0,0],[1,1],[1,0],[-1,1]]))
    print(sol.minCostConnectPoints([[2,-3],[-17,-8],[13,8],[-17,-15]]))



