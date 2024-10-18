/*<문제>
A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:
    A[0] = -3
    A[1] = 1
    A[2] = 2
    A[3] = -2
    A[4] = 5
    A[5] = 6
contains the following example triplets:

(0, 1, 2), product is −3 * 1 * 2 = −6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60
Your goal is to find the maximal product of any triplet.

Write a function:

int solution(int A[], int N);

that, given a non-empty array A, returns the value of the maximal product of any triplet.


Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−1,000..1,000].*/

/*풀이
    1. 일단 오름차순으로 sort를 한다.
    2. maxproduct1 : A[0], A[1], A[A.size()-1]  #-값 2개와 가장 큰 +값 하나
        maxproduct2 : A[A.size()-1], A[A.size()-2], A[A.size()-3] # 큰 값 3개
    3. 2에서 얻은 두 값 중 큰 거 반환.
*/

#include <stdio.h>
#include <stdlib.h>

int compare_ascending(const void* a, const void* b) {
    const int* x = (int*) a;
    const int* y = (int*) b;

    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;

    return 0;
}

int solution(int A[], int N){
    qsort(A, N, sizeof(int), compare_ascending);

    int maxproduct1 = A[0] * A[1] * A[N-1];
    int maxproduct2 = A[N-1] * A[N-2] * A[N-3];

    return maxproduct1 > maxproduct2 ? maxproduct1 : maxproduct2;
}

//----------번외 : 최대곱과 그 때의 index까지 같이 반환해야 한다면...? ---------------------
#include <stdio.h>
#include <stdlib.h>

//인덱스를 함께 저장하는 구조체 정의
typedef struct {
    int value;
    int index;
} IndexElement;

//비교함수 
int compare(const void *a, const void *b){
    return (((IndexElement*)a)->value) - (((IndexElement*)b)->value);
}

int* solution_with_index(int A[], int N, int result[]){
    //(값, 인덱스)를 저장하는배열 생성
    IndexElement* indexed_A = (IndexElement*)malloc(sizeof(IndexElement) * N);
    for (int i = 0; i< N ; i++){
        indexed_A[i].value = A[i];
        indexed_A[i].index = i;
    }
    //indexed_A 정렬
    qsort(indexed_A, N, sizeof(IndexElement), compare);

    //maxproduct (후보 1,2)
    int maxproduct1 = indexed_A[N-1].value * indexed_A[N-2].value * indexed_A[N-3].value;
    int indices1[3] = {indexed_A[N-1].index, indexed_A[N-2].index, indexed_A[N-3].index};
    
    int maxproduct2 = indexed_A[0].value * indexed_A[1].value * indexed_A[N-1].value;
    int indices2[3] = {indexed_A[0].index, indexed_A[1].index, indexed_A[N-1].index};

    //더 큰 곱을 가진 인덱스 반환
    if (maxproduct1 > maxproduct2) {
        result[0] = indices1[0];
        result[1] = indices1[1];
        result[2] = indices1[2];
    } else {
        result[0] = indices2[0];
        result[1] = indices2[1];
        result[2] = indices2[2];
    }
    free(indexed_A);

    return result;
}

int main() {
    int A[] = {-3, 1, 2, -2, 5, 6};
    int N = sizeof(A) / sizeof(A[0]);
    int* result; // 도는 int result[3];
    solution_with_index(A, N, result);
    
    printf("Indices: (%d, %d, %d)\n", result[0], result[1], result[2]);  // 예상 출력: (2, 4, 5)
    return 0;
}
