#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a)>(b) ? (a):(b))

int compare(const void* a, const void* b) {
    // Convert the void pointers to int pointers and dereference them
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    // Return comparison result
    return (int_a > int_b) - (int_a < int_b);  // returns -1, 0, or 1
}

int solution(int A[], int N){
    /* Compare between the product of 2 smallest and largest vs. product of 3 largest */
    
    qsort(A, N, sizeof(int), compare);
    
    int cand_1 = A[0]*A[1]*A[N-1];
    int cand_2 = A[N-3]*A[N-2]*A[N-1];

    return MAX(cand_1, cand_2);
}