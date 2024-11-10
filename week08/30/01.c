#include <stdio.h>

int solution(int K, int A[], int N) {
    int count = 0;   
    int current_length = 0;    

    for (int i = 0; i < N; i++) {
        current_length += A[i];    

        if (current_length >= K) {
            count++;               
            current_length = 0;    
        }
    }

    return count;    
}

int main() {
    int A[] = {1, 2, 3, 4, 1, 1, 3};
    int N = sizeof(A) / sizeof(A[0]);
    int K = 4;

    printf("Max number of ropes: %d\n", solution(K, A, N)); 

    return 0;
}
