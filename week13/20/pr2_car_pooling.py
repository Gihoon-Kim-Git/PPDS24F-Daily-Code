class Solution:
    def carPooling(self, trips: list[list[int]], capacity: int) -> bool:
        lst = [0]*1000
        for x in trips:
            for i in range(x[1],x[2]):
                lst[i] += x[0]
            if max(lst) > capacity : return False  
        return True
    
# class Solution:
#     def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
#         # 타임라인 배열 생성 (최대 위치 1000)
#         timeline = [0] * 1001
        
#         # 승객 변화량 기록
#         for passengers, start, end in trips:
#             timeline[start] += passengers  # 시작 위치에서 승객 추가
#             timeline[end] -= passengers    # 종료 위치에서 승객 제거
        
#         # Prefix Sum 계산하여 최대 용량 확인
#         current_capacity = 0
#         for passengers in timeline:
#             current_capacity += passengers
#             if current_capacity > capacity:
#                 return False
        
#         return True

# import heapq

# class Solution:
#     def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
#         # 시작 시간 기준으로 정렬
#         trips.sort(key=lambda x: x[1])
#         heap = []  # 최소 힙: (종료 시간, 승객 수)
        
#         current_capacity = 0
        
#         for passengers, start, end in trips:
#             # 현재 시간(start) 이전에 내릴 승객 처리
#             while heap and heap[0][0] <= start:
#                 _, exited_passengers = heapq.heappop(heap)
#                 current_capacity -= exited_passengers
            
#             # 새로운 승객 태우기
#             heapq.heappush(heap, (end, passengers))
#             current_capacity += passengers
            
#             # 용량 초과 확인
#             if current_capacity > capacity:
#                 return False
        
#         return True
