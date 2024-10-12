#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a:b;
}

int NumSolitaire(int A[], int N) {
    int* result = (int*)malloc(N*sizeof(int));
    result[0] = A[0]; // N == 1
    result[1] = A[0] + A[1]; // N==2
    int check;
    if (N>2) { // N >=3
        check = max(result[0], result[1]);
        result[2] = check + A[2];}
    if (N>3) { // N >=4
        check = max(check, result[2]);
        result[3] = check + A[3];}
    if (N>4) { // N >=5
        check = max(check, result[3]);
        result[4] = check + A[4];
    }
    if (N>5) { // N >=6
        check = max(check, result[4]);
        result[5] = check + A[5];
    }
    if (N>6) { // N >=7
        check = max(check, result[5]);
        result[6] = check + A[6];
    }
    int check2 = INT32_MIN;
    if (N>7) {
        for (int i =7; i<N; i++) {
            for (int j=N-8; j<N-1; j++) {
                check2 = max(check2, result[j]);
            }
            result[i] = check2 + A[i];
        }
    }

    int final = result[N-1];
    free(result);
    return final;
}

int main(void) {

    int test2_1[3] = {1, 2};
    int result1 = NumSolitaire(test2_1, 2);
    printf("result1 is %d\n", result1);
    int test2_2[10] = {10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000};
    int result2 = NumSolitaire(test2_2, 9);
    printf("result2 is %d\n", result2);
    return 1;
}