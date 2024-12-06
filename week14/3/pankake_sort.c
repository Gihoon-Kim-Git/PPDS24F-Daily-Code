#include <stdio.h>
#include <stdlib.h>

// 배열의 0부터 k-1까지를 뒤집는 함수
void flip(int* arr, int k) {
    int left = 0;
    int right = k - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

// 배열에서 최대값의 인덱스를 찾는 함수
int findMaxIndex(int* arr, int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// 팬케이크 정렬 함수
int* pancakeSort(int* arr, int arrSize, int* returnSize) {
    // 결과를 저장할 동적 배열
    int* result = (int*)malloc(arrSize * 10 * sizeof(int));
    *returnSize = 0;

    // 배열을 반복적으로 정렬
    for (int currSize = arrSize; currSize > 1; currSize--) {
        // 현재 크기까지의 배열에서 최대값의 인덱스를 찾음
        int maxIndex = findMaxIndex(arr, currSize);

        // 최대값이 마지막 위치에 있지 않으면 뒤집기
        if (maxIndex != currSize - 1) {
            // 최대값을 첫 번째로 가져오기 위해 뒤집기
            if (maxIndex > 0) {
                flip(arr, maxIndex + 1);
                result[(*returnSize)++] = maxIndex + 1;
            }
            // 최대값을 현재 크기 위치로 보내기 위해 뒤집기
            flip(arr, currSize);
            result[(*returnSize)++] = currSize;
        }
    }

    return result;
}

// 테스트용 메인 함수
int main() {
    int arr[] = {3, 2, 4, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int returnSize;

    // 팬케이크 정렬 실행
    int* result = pancakeSort(arr, arrSize, &returnSize);

    // 결과 출력
    printf("Flips: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // 정렬된 배열 확인
    printf("Sorted array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(result); // 동적 메모리 해제

    return 0;
}
