#include <stdio.h>
#include <stdlib.h>

/**
 * 다음 큰 요소를 찾는 함수
 * @param nums1: 첫 번째 배열 (부분 배열)
 * @param nums1Size: nums1의 크기
 * @param nums2: 두 번째 배열 (전체 배열)
 * @param nums2Size: nums2의 크기
 * @param returnSize: 결과 배열 크기 (출력 파라미터)
 * @return: nums1의 각 요소에 대한 다음 큰 요소를 저장한 배열
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // 결과 배열 동적 할당
    int* result = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size; // 결과 배열의 크기는 nums1과 동일

    // nums1의 각 요소에 대해 반복
    for (int i = 0; i < nums1Size; i++) {
        int found = 0; // nums2에서 nums1[i]를 찾았는지 여부
        int nextGreater = -1; // 기본값: 다음 큰 요소 없음(-1)

        // nums2 배열 순회
        for (int j = 0; j < nums2Size; j++) {
            // nums2에서 nums1[i]와 동일한 값을 찾음
            if (nums2[j] == nums1[i]) {
                found = 1; // nums1[i]를 nums2에서 찾음
            }
            // nums1[i]를 찾은 이후 첫 번째로 큰 요소를 탐색
            if (found && nums2[j] > nums1[i]) {
                nextGreater = nums2[j]; // 다음 큰 요소를 저장
                break; // 첫 번째 큰 요소를 찾았으므로 루프 종료
            }
        }
        // 결과 배열에 다음 큰 요소 저장
        result[i] = nextGreater;
    }

    return result; // 결과 배열 반환
}

// 테스트용 메인 함수
int main() {
    // 테스트 케이스 1
    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int returnSize;

    int* result = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);

    printf("Output: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result); // 동적 메모리 해제

    // 테스트 케이스 2
    int nums3[] = {2, 4};
    int nums4[] = {1, 2, 3, 4};

    result = nextGreaterElement(nums3, 2, nums4, 4, &returnSize);

    printf("Output: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result); // 동적 메모리 해제

    return 0;
}
