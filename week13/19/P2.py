import heapq

class Solution(object):
    def carPooling(self, trips, capacity):
        maxval = 0
        start = []
        end = []
        for trip in trips: # start 기준 오름차순 -> (from, to, passengers)
            start.append([trip[1], trip[2], trip[0]])
        start.sort()
        for k in range(len(start)):
            while (end and end[0][0] <= start[k][0]):
                maxval -= end[0][1]
                heapq.heappop(end)
            # end 기준 오름차순 -> (to, passengers)
            heapq.heappush(end, [start[k][1], start[k][2]])
            maxval += start[k][2]
            if maxval > capacity:
                return False
        return True

if __name__ == "__main__":
    trips = [[2,1,5],[3,3,7]]
    answer = Solution()
    print(answer.carPooling(trips, 4))
    print(answer.carPooling(trips, 5))
    trips = [[3,2,8],[4,4,6],[10,8,9]]
    print(answer.carPooling(trips, 11))
    trips = [[2,2,6],[2,4,7],[8,6,7]]
    print(answer.carPooling(trips, 11))
    trips = [[7,5,6],[6,7,8],[10,1,6]]
    print(answer.carPooling(trips, 16))