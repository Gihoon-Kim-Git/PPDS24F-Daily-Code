#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // Case 1: 중간 값이 오른쪽 끝 값보다 큰 경우 -> 최솟값은 오른쪽에 있음
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        // Case 2: 중간 값이 오른쪽 끝 값보다 작은 경우 -> 최솟값은 왼쪽에 있음
        else if (nums[mid] < nums[right]) {
            right = mid;
        }
        // Case 3: 중간 값과 오른쪽 값이 같은 경우 -> 중복 처리 (right 범위를 줄임)
        else {
            right--;
        }
    }

    return nums[left];
}

int main() {
    int nums1[] = {1, 3, 5};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Minimum in nums1: %d\n", findMin(nums1, size1)); 

    int nums2[] = {2, 2, 2, 0, 1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Minimum in nums2: %d\n", findMin(nums2, size2)); 

    return 0;
}
