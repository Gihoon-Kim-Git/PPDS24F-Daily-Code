#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char num1[32], num2[32];
    sprintf(num1, "%s%s", *(char **)a, *(char **)b);
    sprintf(num2, "%s%s", *(char **)b, *(char **)a);
    return strcmp(num2, num1); // Sort in descending order
}

char *largestNumber(int *nums, int numsSize) {
    char **numStrs = (char **)malloc(numsSize * sizeof(char *));
    for (int i = 0; i < numsSize; i++) {
        numStrs[i] = (char *)malloc(12 * sizeof(char));
        sprintf(numStrs[i], "%d", nums[i]);
    }

    qsort(numStrs, numsSize, sizeof(char *), compare);

    char *result = (char *)malloc(numsSize * 12 * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < numsSize; i++) {
        strcat(result, numStrs[i]);
        free(numStrs[i]);
    }
    free(numStrs);

    if (result[0] == '0') {
        result[1] = '\0'; // Handle case where all numbers are zeros
    }

    return result;
}

// Example usage
int main() {
    int nums[] = {3, 30, 34, 5, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    char *result = largestNumber(nums, numsSize);
    printf("%s\n", result); // Output: "9534330"
    free(result);
    return 0;
}
