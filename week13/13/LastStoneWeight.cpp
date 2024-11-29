#include <queue>
#include <vector>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        // 최대 힙을 구현하는 우선순위 큐
        std::priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int stone1 = pq.top(); // 가장 무거운 돌
            pq.pop();
            int stone2 = pq.top(); // 두 번째로 무거운 돌
            pq.pop();

            // 두 돌의 무게가 다르면 남은 무게를 다시 삽입
            if (stone1 != stone2) {
                pq.push(stone1 - stone2);
            }
        }

        // 큐가 비어 있으면 0을 반환, 그렇지 않으면 남은 돌의 무게 반환
        return pq.empty() ? 0 : pq.top();
    }
};


//아래는 수동힙(max heap) 정렬을 사용하여 문제를 해결한 예시

// #include <vector>
// #include <iostream>

// class Solution {
// public:
//     void heapify(std::vector<int>& heap, int n, int i) {
//         int largest = i; // 부모 노드
//         int left = 2 * i + 1; // 왼쪽 자식
//         int right = 2 * i + 2; // 오른쪽 자식

//         // 왼쪽 자식이 더 크다면 갱신
//         if (left < n && heap[left] > heap[largest])
//             largest = left;

//         // 오른쪽 자식이 더 크다면 갱신
//         if (right < n && heap[right] > heap[largest])
//             largest = right;

//         // 부모가 자식보다 작다면 스왑 후 재귀 호출
//         if (largest != i) {
//             std::swap(heap[i], heap[largest]);
//             heapify(heap, n, largest);
//         }
//     }

//     int lastStoneWeight(std::vector<int>& stones) {
//         // 1. 최대 힙 구성
//         int n = stones.size();
//         for (int i = n / 2 - 1; i >= 0; i--) {
//             heapify(stones, n, i);
//         }

//         // 2. 돌을 하나씩 처리
//         while (n > 1) {
//             // 가장 무거운 두 돌 꺼내기
//             int stone1 = stones[0]; // 가장 큰 돌
//             std::swap(stones[0], stones[n - 1]); // 마지막과 교체
//             n--; // 힙 크기 감소
//             heapify(stones, n, 0); // 힙 재구성
//             int stone2 = stones[0]; // 두 번째로 큰 돌
//             std::swap(stones[0], stones[n - 1]); // 마지막과 교체
//             n--; // 힙 크기 감소
//             heapify(stones, n, 0); // 힙 재구성

//             // 돌을 부딪힌 결과 삽입
//             if (stone1 != stone2) {
//                 stones[n] = stone1 - stone2; // 남은 무게
//                 n++;
//                 int i = n - 1; // 새로 삽입된 위치에서 위로 올리기
//                 while (i > 0 && stones[i] > stones[(i - 1) / 2]) {
//                     std::swap(stones[i], stones[(i - 1) / 2]);
//                     i = (i - 1) / 2;
//                 }
//             }
//         }

//         // 마지막 남은 돌 반환
//         return n == 0 ? 0 : stones[0];
//     }
// };
