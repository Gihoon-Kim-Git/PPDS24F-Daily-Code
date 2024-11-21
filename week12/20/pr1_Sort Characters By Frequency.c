#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 문자 빈도를 저장할 구조체
typedef struct {
    char ch;   // 문자
    int freq;  // 빈도
} CharFreq;

// 비교 함수 (빈도 내림차순, 빈도가 같으면 문자 기준 오름차순)
int compare(const void *a, const void *b) {
    CharFreq *x = (CharFreq *)a;
    CharFreq *y = (CharFreq *)b;
    if (y->freq != x->freq) {
        return y->freq - x->freq; // 빈도 내림차순
    }
    return x->ch - y->ch; // 문자 오름차순
}

char *frequencySort(char *s) {
    int freq[128] = {0}; // ASCII 문자 빈도 계산

    // 빈도 계산
    for (int i = 0; s[i] != '\0'; i++) {
        freq[(int)s[i]]++;
    }

    // 빈도가 있는 문자들로 CharFreq 배열 생성
    CharFreq charFreqs[128];
    int count = 0; // 실제 문자의 개수
    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0) {
            charFreqs[count].ch = (char)i;
            charFreqs[count].freq = freq[i];
            count++;
        }
    }

    // CharFreq 배열 정렬
    qsort(charFreqs, count, sizeof(CharFreq), compare);

    // 결과 문자열 생성
    int len = strlen(s);
    char *result = (char *)malloc((len + 1) * sizeof(char));
    int idx = 0;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < charFreqs[i].freq; j++) {
            result[idx++] = charFreqs[i].ch;
        }
    }
    result[idx] = '\0'; // NULL 문자로 끝내기

    return result;
}
