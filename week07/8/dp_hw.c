//1. pascal's triangle 2
int* getRow(int rowIndex, int* returnSize) {
    
    int** dp = (int**)malloc(sizeof(int*)*(rowIndex+1));
    for (int i = 0; i < rowIndex+1; i++) {
        dp[i] = (int*)malloc(sizeof(int)*(i+1));
    }
    *returnSize = rowIndex+1;

    dp[0][0] = 1;

    for (int i = 1; i <= rowIndex; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }

    return dp[rowIndex];
}




//2. quicksort
void quickSort(int arr[], int low, int high) {
    if (low >= high) return;  // Base case: If the array has 1 or 0 elements, return
    
    // Partition the array and get the pivot index
    int pivotIndex = partition(arr, low, high);
    
    // Recursively sort the left part (elements smaller than the pivot)
    quickSort(arr, low, pivotIndex - 1);
    
    // Recursively sort the right part (elements larger than the pivot)
    quickSort(arr, pivotIndex + 1, high);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choose the pivot as the first element
    int left = low + 1;
    int right = high;
    
    while (left <= right) {
        // Move the left pointer to the right until an element larger than the pivot is found
        while (left <= right && arr[left] <= pivot) {
            left++;
        }
        
        // Move the right pointer to the left until an element smaller than the pivot is found
        while (left <= right && arr[right] > pivot) {
            right--;
        }
        
        // Swap elements if left and right haven't crossed yet
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    
    // Place the pivot in its correct position by swapping it with arr[right]
    arr[low] = arr[right];
    arr[right] = pivot;
    
    // Return the final position of the pivot
    return right;
}



//3. Max product of three

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int solution(int A[], int N) {
    qsort(A, N, sizeof(int), compare);

    int max_num1 = A[N-1]*A[N-2]*A[N-3];
    int max_num2 = A[N-1]*A[0]*A[1];

    return (max_num1 > max_num2) ? max_num1 : max_num2;
}

/*C++
int solution(vector<int>& A) {
        // 배열을 정렬
        sort(A.begin(), A.end());
        
        int N = A.size();
        
        // 세 개의 가장 큰 숫자의 곱 계산
        int max1 = A[N-1] * A[N-2] * A[N-3];
        
        // 두 개의 가장 작은 숫자와 가장 큰 숫자의 곱 계산
        int max2 = A[0] * A[1] * A[N-1];
        
        // 두 값 중 최대값 반환
        return max(max1, max2);
    }
*/




//4. MinMax Division
#include <stdio.h>
#include <limits.h>

int check(int A[], int N, int K, int MaxSum) {
    int blockCount = 1;
    int currentSum = 0;
    for (int i = 0; i < N; i++) {
        printf("Checking value: %d, currentSum: %d, blockCount: %d\n", A[i], currentSum, blockCount);
        if (currentSum + A[i] > MaxSum) {
            blockCount++;
            currentSum = A[i];
            printf("New block needed, blockCount: %d, currentSum reset to: %d\n", blockCount, currentSum);
            if (blockCount > K) {
                printf("Block count exceeded K: %d, returning false\n", K);
                return 0;
            }
        } else {
            currentSum += A[i];
            printf("Value added to currentSum: %d\n", currentSum);
        }
    }
    return 1;
}

int solution(int K, int M, int A[], int N) {
    int maxValue = 0;
    int totalSum = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > maxValue) {
            maxValue = A[i];
        }
        totalSum += A[i];
    }

    printf("Initial maxValue: %d, totalSum: %d\n", maxValue, totalSum);

    int result = totalSum;
    int L = maxValue;
    int U = totalSum;
    while (L <= U) {
        int Mid = (L + U) / 2;
        printf("Binary search, L: %d, U: %d, Mid: %d\n", L, U, Mid);
        if (check(A, N, K, Mid)) {
            result = Mid;
            U = Mid - 1;
            printf("Mid is feasible, updating result: %d, U: %d\n", result, U);
        } else {
            L = Mid + 1;
            printf("Mid is not feasible, updating L: %d\n", L);
        }
    }
    return result;
}






//5. Search 2d matrix 2
#include <stdbool.h>

int binary_search(int L[], int n, int v) {
    int start = 0;
    int end = n-1;
    while (start != end +1) {
        int mid = (start+end)/2;
        if (L[mid] < v) start = mid+1;
        else end = mid-1;
    }
    if (start < n && L[start] == v) return start;
    else return -1;

}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    for (int i = 0; i < matrixSize; i++) {
        int ans = binary_search(matrix[i], matrixColSize[i], target);
        if (ans == -1) {
            continue;
        }
        else {
            return true;
        }
    }

    return false;
}