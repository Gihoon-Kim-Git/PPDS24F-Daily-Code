#include <stdio.h>
#include <stdlib.h>

int* mysort(int A[], int N){
    for(int i = 0; i < N; i++){
        int min = i;
        for(int j = i+1; j < N; j++){
            if(A[j] < A[min]){
                min = j;
            }
        }
        int temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
    return A;
}

int solution(int A[], int N){
    int* a = mysort(A, N);
    int max;
    if(a[N-2] * a[N-1] * a[N-3] > a[0] * a[1] * a[N-1]){
        max = a[N-2] * a[N-1] * a[N-3];
    }
    else{
        max = a[0] * a[1] * a[N-1];
    }
    return max;
}




int main() {
    int A1[] = {1, 2, 3, 4, 5};           // Expected: 60 (3*4*5)
    int A2[] = {-10, -10, 5, 2};          // Expected: 500 (-10*-10*5)
    int A3[] = {-5, 4, 3, 2, 1};          // Expected: 12 (4*3*2)
    int A4[] = {-3, -2, -1, -5, -4};      // Expected: -6 (-1*-2*-3)
    int A5[] = {0, 0, 0, 0, 0};           // Expected: 0 (all values are 0)

    printf("Test Case 1: %d\n", solution(A1, 5));
    printf("Test Case 2: %d\n", solution(A2, 4));
    printf("Test Case 3: %d\n", solution(A3, 5));
    printf("Test Case 4: %d\n", solution(A4, 5));
    printf("Test Case 5: %d\n", solution(A5, 5));

    return 0;
}