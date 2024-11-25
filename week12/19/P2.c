#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    char ab[1000], ba[1000];
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    return strcmp(ba, ab);
}

char* largestNumber(int* nums, int numsSize) {
    static char answer[1000];
    answer[0] = '\0';
    if (nums == NULL || numsSize == 0) return "";
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i=0; i<numsSize; i++) {
        int len = strlen(answer);
        sprintf(answer + len, "%d", nums[i]);
    }
    if (answer[0] == '0') return "0";
    return answer;
}

int main() {
    int nums1[] = {10, 2};
    int nums2[] = {3, 30, 34, 5, 9};

    printf("%s\n", largestNumber(nums1, sizeof(nums1)/sizeof(nums1[0])));
    printf("%s\n", largestNumber(nums2, sizeof(nums2)/sizeof(nums2[0])));
    
    return 0;
}