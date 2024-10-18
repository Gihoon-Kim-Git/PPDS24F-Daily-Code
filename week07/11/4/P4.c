#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool can_split(int A[], int max, int K, int N){
    int sum = 0;
    int arrnum = 1;
    for(int i = 0; i < N; i++){
        if(sum + A[i] > max){
            arrnum++;
            sum = A[i];
            if(arrnum > K){
                return false;
            }
        }
        else{
            sum += A[i];
        }
    }
    return true;

}

int solution(int K, int M, int A[], int N){
    int left = M;
    int right = 0;
    for(int i =0; i< N; i++){
        right += A[i];
    }
    int result = right;
    while(left <= right){
        int mid = (right+left)/2;
        if(can_split(A, mid, K, N)){
            result = mid;
            right--;
        }
        else{
            left++;
        }
    }
    return result;
}

int main() {
    // 테스트 케이스 1
    int A1[] = {7, 2, 5, 10, 8};
    int K1 = 2;
    int M1 = 10;
    int N1 = sizeof(A1) / sizeof(A1[0]);
    printf("Test Case 1 Result: %d\n", solution(K1, M1, A1, N1)); // Expected output: 18

    // 테스트 케이스 2
    int A2[] = {1, 2, 3, 4, 5};
    int K2 = 3;
    int M2 = 5;
    int N2 = sizeof(A2) / sizeof(A2[0]);
    printf("Test Case 2 Result: %d\n", solution(K2, M2, A2, N2)); // Expected output: 6

    // 테스트 케이스 3
    int A3[] = {5, 6, 7, 8, 9, 10};
    int K3 = 2;
    int M3 = 10;
    int N3 = sizeof(A3) / sizeof(A3[0]);
    printf("Test Case 3 Result: %d\n", solution(K3, M3, A3, N3)); // Expected output: 26

    // 테스트 케이스 4
    int A4[] = {1, 1, 1, 1, 1, 1, 1, 1};
    int K4 = 4;
    int M4 = 1;
    int N4 = sizeof(A4) / sizeof(A4[0]);
    printf("Test Case 4 Result: %d\n", solution(K4, M4, A4, N4)); // Expected output: 2

    // 테스트 케이스 5
    int A5[] = {100, 200, 300, 400, 500};
    int K5 = 2;
    int M5 = 500;
    int N5 = sizeof(A5) / sizeof(A5[0]);
    printf("Test Case 5 Result: %d\n", solution(K5, M5, A5, N5)); // Expected output: 900

    return 0;
}