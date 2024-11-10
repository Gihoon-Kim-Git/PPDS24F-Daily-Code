#include <stdio.h>
#include <stdlib.h>

int findMinHelp(int* nums, int start, int end) {
    if (end - start == 0) return nums[start];
    int mid = (start + end) / 2;
    int left = findMinHelp(nums, start, mid);
    int right = findMinHelp(nums, mid+1, end);
    return (left < right ? left : right);
}

int findMin(int* nums, int numsSize) {
    return findMinHelp(nums, 0, numsSize-1);
}

int main() {
    // int nums[] = {1,3,5};
    int nums[] = {2,2,2,0,1};
    printf("%d\n", findMin(nums, sizeof(nums)/sizeof(int)));

    return 0;
}