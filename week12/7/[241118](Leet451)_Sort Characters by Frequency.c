/*Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.*/

/*Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.*/

/*수도코드
    1. 128 ascii코드 길이와 같은 array 정의
    2. 단어의 글자를 하나하나 순회하면서 array에다가 횟수를 더한다
    3. 각 글자별 횟수가 정리된 array의 횟수를 담을 array 하나 만들기
    4. 횟수담은 array를 내림차순으로 정렬한다.
    5. 횟수담은 array의 for문을 돌면서 '글자별 횟수 정리된 array'와 값이 일치하면,
        해당 횟수 * 글자 를 answer에 넣고, 다 넣었으면 마지막에 '\0' 넣어주기
    6. 반환.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_descending(const void* a, const void* b) {
    const int* x = (int*) a;
    const int* y = (int*) b;

    if (*x > *y)
        return -1;
    else if (*x < *y)
        return 1;

    return 0;
}

char* frequencySort(char* s) {
    int str_len = strlen(s);

    char* answer = (char*)malloc(sizeof(char) * (str_len+1));
    int ans_i = 0;

    int char_count[128] = {0};

    for (int i = 0; i < str_len; i++){
        char_count[s[i]]++;
    }    

    int counts[128] = {0};
    int count_i = 0;
    //A부터 z까지 범위, 숫자 0~9
    for (int i = 48; i< 123; i++){
        if (char_count[i] > 0){
            counts[count_i] = char_count[i];
            count_i++; // unique alphabet 수
        } 
    }

    //내림차순 정렬
    qsort(counts, count_i, sizeof(int), compare_descending);

    for (int i = 0; i < count_i; i++){
        for (int j = 48; j < 123; j++){
            if (counts[i] == char_count[j]){
                while (char_count[j] > 0){
                    answer[ans_i++] = j;  //(char)j가 아니라 그냥 j 적으면 됨.
                    char_count[j]--;}
            }
        }
    }
    answer[ans_i] = '\0';

    return answer;
}