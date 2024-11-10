#include <limits.h>
//Time Out
int findCrossingProduct(int A[], int low, int mid, int high) {
    int maxProduct = INT_MIN;
    
    // 왼쪽 구간에서 2개, 오른쪽에서 1개를 선택하는 경우
    for (int i = low; i <= mid; i++) {
        for (int j = i + 1; j <= mid; j++) {
            for (int k = mid + 1; k <= high; k++) {
                int product = A[i] * A[j] * A[k];
                if (product > maxProduct) {
                    maxProduct = product;
                }
            }
        }
    }
    
    // 왼쪽 구간에서 1개, 오른쪽에서 2개를 선택하는 경우
    for (int i = low; i <= mid; i++) {
        for (int j = mid + 1; j <= high; j++) {
            for (int k = j + 1; k <= high; k++) {
                int product = A[i] * A[j] * A[k];
                if (product > maxProduct) {
                    maxProduct = product;
                }
            }
        }
    }
    
    return maxProduct;
}

int maxProductDC(int A[], int low, int high) {
    // 기저 조건: 구간의 길이가 3인 경우
    if (high - low + 1 == 3) {
        return A[low] * A[low + 1] * A[low + 2];
    }
    // 구간의 길이가 3보다 작은 경우 처리
    if (high - low + 1 < 3) {
        return INT_MIN;
    }
    
    int mid = (low + high) / 2;
    
    // 1. 왼쪽 구간의 최대 곱
    int leftProduct = maxProductDC(A, low, mid);
    
    // 2. 오른쪽 구간의 최대 곱
    int rightProduct = maxProductDC(A, mid + 1, high);
    
    // 3. 경계를 걸쳐 있는 경우의 최대 곱
    int crossProduct = findCrossingProduct(A, low, mid, high);
    
    // 세 가지 경우 중 최대값 반환
    int maxProduct = leftProduct;
    if (rightProduct > maxProduct) maxProduct = rightProduct;
    if (crossProduct > maxProduct) maxProduct = crossProduct;
    
    return maxProduct;
}

int solution(int A[], int N) {
    if (N < 3) return 0;  // 배열 길이가 3 미만인 경우 처리
    return maxProductDC(A, 0, N - 1);
}