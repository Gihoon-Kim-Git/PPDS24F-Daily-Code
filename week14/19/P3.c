#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* answer = (int*)malloc(nums1Size * sizeof(int));
    int* h = (int*)malloc(10001 * sizeof(int));
    *returnSize = nums1Size;
    for (int i=nums2Size-1; i>=0; i--) {
        if (i == nums2Size-1) h[nums2[i]] = -1;
        else {
            if (nums2[i] < nums2[i+1]) h[nums2[i]] = nums2[i+1];
            else {
                int iter = i;
                while (iter < nums2Size-1) {
                    h[nums2[i]] = -1;
                    if (nums2[i] < h[nums2[iter+1]]) {
                        h[nums2[i]] = h[nums2[iter+1]];
                        break;
                    }
                    iter += 1;
                }
            }
        }
    }
    for (int j=0; j<nums1Size; j++) answer[j] = h[nums1[j]];
    return answer;
}

int main() {
    int nums1[3] = {4,1,2};
    int nums2[4] = {1,3,4,2};
    int returnSize;
    int* answer1 = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", answer1[i]);
    }
    printf("\n");

    free(answer1);
    return 0;
}