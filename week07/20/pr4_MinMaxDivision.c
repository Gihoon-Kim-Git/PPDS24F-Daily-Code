// C 버전
int check_division_possible(int A[], int N, int K, long long max_sum) {
    int blocks = 1;
    long long current_sum = 0;
    
    for(int i = 0; i < N; i++) {
        if(A[i] > max_sum) return 0;
        
        if(current_sum + A[i] > max_sum) {
            blocks++;
            current_sum = A[i];
        } else {
            current_sum += A[i];
        }
        
        if(blocks > K) return 0;
    }
    
    return 1;
}

int solution(int K, int M, int A[], int N) {
    if(K == 1) {
        long long sum = 0;
        for(int i = 0; i < N; i++) sum += A[i];
        return (int)sum;
    }
    
    if(K >= N) {
        int max_elem = A[0];
        for(int i = 1; i < N; i++) {
            if(A[i] > max_elem) max_elem = A[i];
        }
        return max_elem;
    }
    
    // 이진 탐색 범위 설정
    int max_elem = A[0];
    long long total_sum = A[0];
    for(int i = 1; i < N; i++) {
        if(A[i] > max_elem) max_elem = A[i];
        total_sum += A[i];
    }
    
    long long left = max_elem;
    long long right = total_sum;
    int result = (int)right;
    
    while(left <= right) {
        long long mid = (left + right) / 2;
        
        if(check_division_possible(A, N, K, mid)) {
            result = (int)mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}
