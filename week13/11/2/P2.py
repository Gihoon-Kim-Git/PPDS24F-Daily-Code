class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        start = []
        end = []
        for trip in trips:
            start.append([trip[1], trip[0]])
            end.append([trip[2], trip[0]])
        start.sort(key=lambda x: x[0])
        end.sort(key=lambda x: x[0])
        m = 0
        n = 0
        curpas = 0
        while(m < len(start) and n < len(end)):
            if start[m][0] < end[n][0]:
                curpas += start[m][1]
                m+=1
                if curpas > capacity:
                    return False
            else:
                curpas -= end[n][1]
                n+=1
        return True