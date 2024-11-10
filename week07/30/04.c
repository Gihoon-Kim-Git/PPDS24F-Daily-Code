#include <stdio.h>

// [1] 배열을 K개의 블록으로 나눌 때, 주어진 'large_sum' 이하로 나눌 수 있는 블록의 수를 계산
int canDivide(int A[], int N, int K, int large_sum) {
    int block_sum = 0;
    int block_count = 1; // 최소 하나의 블록이 필요함
    
    for (int i = 0; i < N; i++) {
        // [1.1] 현재 원소를 더했을 때, large_sum을 초과하면 새로운 블록을 시작
        if (block_sum + A[i] > large_sum) {
            block_sum = A[i];
            block_count++;
            
            // [1.2] 만약 블록의 수가 K를 초과하면 false 반환
            if (block_count > K) {
                return 0;
            }
        } else {
            block_sum += A[i];
        }
    }
    
    // [1.3] 주어진 large_sum 이하로 K개의 블록으로 나눌 수 있으면 true 반환
    return 1;
}

// [2] 배열을 K개의 블록으로 나누었을 때, 가장 큰 블록의 합을 최소화하는 함수
int solution(int K, int M, int A[], int N) {
    // [2.1] 이진 탐색의 범위를 설정 (left는 배열의 최대 값, right는 배열의 모든 합)
    int left = 0, right = 0;
    
    for (int i = 0; i < N; i++) {
        if (A[i] > left) {
            left = A[i]; // 배열의 최대 값을 left로 설정
        }
        right += A[i];  // 배열의 총합을 right로 설정
    }
    
    // [2.2] 이진 탐색을 통해 최소의 large_sum을 찾음
    while (left <= right) {
        int mid = (left + right) / 2;
        
        // [2.3] mid 값으로 K개의 블록으로 나눌 수 있는지 확인
        if (canDivide(A, N, K, mid)) {
            right = mid - 1;  // 나눌 수 있으면 더 작은 값을 탐색
        } else {
            left = mid + 1;   // 나눌 수 없으면 더 큰 값을 탐색
        }
    }
    
    // [2.4] left는 가능한 최소의 large_sum이 됨
    return left;
}

int main() {
    int A[] = {2, 1, 5, 1, 2, 2, 2};
    int N = sizeof(A) / sizeof(A[0]);
    int K = 3;
    int M = 5;
    
    int result = solution(K, M, A, N);
    printf("Minimal large sum: %d\n", result);
    
    return 0;  }
