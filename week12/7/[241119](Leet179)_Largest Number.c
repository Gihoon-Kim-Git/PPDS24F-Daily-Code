/*Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.
 */

/*Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109*/

/* 아이디어
    1. 숫자가 아닌 문자열로 두고 내림차순 정렬
    2. 내림차순 정렬할 때, x+y, y+x 를 비교해서 정렬하도록. sort 함수 정의
*/


#include <stdio.h>
#include <stdlib.h>


//x+y, y+x 를 기준으로 비교
int compare_string_comb_desc_1(const void* a, const void* b) {
    char* str_a = *(char**)a;
    char* str_b = *(char**)b;

    // str_a + str_b와 str_b + str_a를 비교
    char ab[100], ba[100];
    sprintf(ab, "%s%s", str_a, str_b); // sprintf : 데이터를 문자열로 변환하고 결과를 문자배열에 저장.
    sprintf(ba, "%s%s", str_b, str_a);

    return strcmp(ba, ab); // 내림차순 정렬
}

//x+y, y+x 를 기준으로 비교 (동일한 함수인데 sprintf를 사용하지 않음)
int compare_string_comb_desc_2(const void* a, const void* b) {
    char* str_a = *(char**)a;
    char* str_b = *(char**)b;

    // 두 문자열 조합
    int len_a = strlen(str_a);
    int len_b = strlen(str_b);

    // ab = str_a + str_b
    char* ab = malloc(len_a + len_b + 1);
    strcpy(ab, str_a);
    strcat(ab, str_b);

    // ba = str_b + str_a
    char* ba = malloc(len_a + len_b + 1);
    strcpy(ba, str_b);
    strcat(ba, str_a);

    // 조합된 문자열 비교
    int result = strcmp(ba, ab); // 내림차순 정렬을 위해 ba와 ab를 비교

    // 동적 메모리 해제
    free(ab);
    free(ba);

    return result;
}


// 정수를 문자열로 변환하는 함수
void intToString(int num, char* str) {
    int i = 0;

    // 음수 처리 (필요 시)
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    // 숫자를 거꾸로 저장
    while (num > 0) {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }

    // 끝에 NULL 문자 추가
    str[i] = '\0';

    // 거꾸로 저장된 문자열을 뒤집음
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}



char* largestNumber(int* nums, int numsSize) {
    // 1. 정수 배열을 문자열 배열로 변환
    char** str_nums = malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; i++) {
        str_nums[i] = malloc(12 * sizeof(char)); // 충분히 큰 크기 (최대 10자리 정수)
        //sprintf(str_nums[i], "%d", nums[i]); // 숫자를 문자열로 변환. 내장함수 sprintf
         intToString(nums[i], str_nums[i]);      // 숫자를 문자열로 변환
    }

    // 2. 문자열 배열 정렬
    qsort(str_nums, numsSize, sizeof(char*), compare_string_comb_desc_1);

    // 3. 결과 문자열 생성
    char* result = malloc(numsSize * 12 * sizeof(char)); // 최대 크기 예상
    result[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        strcat(result, str_nums[i]);  
        // char *strcat(char *dest, const char *src); : dest: 이어붙일 대상 문자열. 문자열의 끝에 새로운 문자열이 추가됩니다. src: 추가할 문자열
    }

    // 4. '0'으로 시작하는 경우 처리
    if (result[0] == '0') {
        result[1] = '\0'; // "0" 반환
    }

    // 5. 메모리 해제
    for (int i = 0; i < numsSize; i++) {
        free(str_nums[i]);
    }
    free(str_nums);

    return result;
}