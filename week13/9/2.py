class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        events = []

        # Step 1: 트립을 이벤트로 변환
        for person, start, end in trips:
            events.append((start, person))  # 탑승 이벤트
            events.append((end, -person))  # 하차 이벤트

        # Step 2: 이벤트를 시간 기준으로 정렬
        # 동일 시간에서는 하차 이벤트를 먼저 처리 (-person이 +person보다 앞서도록)
        events.sort(key=lambda x: (x[0], x[1]))

        # Step 3: 이벤트 처리하며 용량 체크
        current_capacity = 0
        for time, change in events:
            current_capacity += change  # 승객 수 업데이트

            # 차량 용량 초과 체크
            if current_capacity > capacity:
                return False

        # 용량 초과 없이 처리 완료
        return True




