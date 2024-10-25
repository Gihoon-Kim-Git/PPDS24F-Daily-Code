#include <stdio.h>
#include <stdlib.h>

int solution(int K, int A[], int N){
    int result = 0;
    int cur = 0;
    for (int i = 0; i < N; i++){
        if (cur + A[i] >= K){
            result++;
            cur = 0;
        }
        else{
            cur = cur + A[i];
        }
    }
    return result;
}

int main(void){
    int K = 4;
    int A[] = {1, 2, 3, 4, 1, 1, 3};
    int N = 7;
    printf("%d\n", solution(K,A,N));
    return 0;
}