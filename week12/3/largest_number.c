#include <stdio.h>
#include <stdlib.h> // qsort
#include <string.h>

// helper function: compare strings based on custom sorting rule
// quicksort-like approach
/*
const pointers: a value cannot be modified
read-only access in a comparator function, commonly used in qsort
*/
int quickCompare(const void* a, const void* b) {
    // comparator function for string converted array
    // void*: pointer to data of an unspecified type
    // char**: pointer to a char* (pointing to the string stored in char*)
    // *(char**)a
    // : (char**)a casts the generic void* to a char** (pointer to a pointer to a char)
    // : * in front dereferences it, giving the char* (a pointer to the actual string)
    // extracted char* (string pointer) assigned to x
    char* x = *(char**)a;
    char* y = *(char**)b;

    // concatenate strings in both possible orders
    char xy[strlen(x) + strlen(y) + 1];
    char yx[strlen(y) + strlen(x) + 1];
    sprintf(xy, "%s%s", x, y);
    sprintf(yx, "%s%s", y, x);
    // lexicographically compare yx with xy
    // strcmp(yx, xy) < 0 : yx < xy
    // strcmp(yx, xy) > 0 : yx > xy
    // largest concatenation comes first in sorted array (reverse order for descending sort)
    return strcmp(yx, xy);
}


// Main function: form the largest number out of nums array
char* largestNumber(int* nums, int numsSize) {
    // convert element of nums from integer to strings
    char** str_nums = malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; i++) {
        str_nums[i] = malloc(12 * sizeof(char)); // enough to hold any 32-bit integer
        sprintf(str_nums[i], "%d", nums[i]);
    } // str_nums formed!

    // void qsort( void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*) );
    // sort str_nums using custom comparator
    qsort(str_nums, numsSize, sizeof(char*), quickCompare);

    // handle edge case: largest number is 0
    if (strcmp(str_nums[0], "0") == 0) {
        // free memory
        for (int i = 0; i < numsSize; i++) free(str_nums[i]);
        free(str_nums);
        // return "0"
        char* result = malloc(2 * sizeof(char));
        strcpy(result, "0");
        return result;
    }

    // concatenate sorted string numbers into the largest number
    int ans_length = 0;
    for (int i=0; i < numsSize; i++) {
        ans_length += strlen(str_nums[i]);
    }
    // memory allocation for ans
    char* ans = malloc((ans_length + 1) * sizeof(char));
    ans[0] = '\0'; // initialize as empty string
    for (int i = 0; i < numsSize; i++) {
        strcat(ans, str_nums[i]);
        free(str_nums[i]);
    }
    // free memory
    free(str_nums);

    return ans;
}

// example usage
int main() {
    int nums1[] = {10, 2};
    printf("%s\n", largestNumber(nums1, 2)); // Output: "210"

    int nums2[] = {3, 30, 34, 5, 9};
    printf("%s\n", largestNumber(nums2, 5)); // Output: "9534330"

    return 0;
}