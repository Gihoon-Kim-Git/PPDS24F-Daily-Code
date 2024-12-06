#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int* result = (int*)malloc(nums1Size * sizeof(int));
    int* stack = (int*)malloc(nums2Size * sizeof(int));
    int top = -1;
    int map[10001];
    memset(map, -1, sizeof(map));
    
    // Use a monotonic decreasing stack to find the next greater element for each element in nums2
    for (int i = 0; i < nums2Size; i++) {
        while (top != -1 && stack[top] < nums2[i]) {
            map[stack[top--]] = nums2[i];
        }
        stack[++top] = nums2[i];
    }
    
    // Iterate over nums1 and find the next greater elements using the map
    for (int i = 0; i < nums1Size; i++) {
        result[i] = map[nums1[i]];
    }
    
    free(stack);
    return result;
}

// Example usage
int main() {
    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int returnSize;
    int* result = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}
