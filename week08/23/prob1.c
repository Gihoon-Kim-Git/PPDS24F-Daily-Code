#include <stdio.h>

int max_ropes_greater_than_k(int K, int A[], int n){
    int count = 0;
    int length = 0;
    for (int i = 0; i < n; i++){
        length += A[i];
        if (length >= K){
            count ++;
            length = 0;
        }
    }
    return count;
}

int main(){
    int A[] = {1,2,3,4,1,1,3};
    int K = 4;
    int n = sizeof(A) / sizeof(A[0]);
    int result = max_ropes_greater_than_k(K, A, n);
    printf("The answer is: %d \n", result);
}