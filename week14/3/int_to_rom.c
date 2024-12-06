#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 숫자를 로마 숫자로 변환하는 함수
char* intToRoman(int num) {
    // 로마 숫자의 값과 해당 기호를 저장한 배열
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    // 결과 문자열을 저장하기 위한 동적 메모리 할당
    // 최악의 경우 (3999) "MMMCMXCIX"가 필요하며 이는 최대 15개의 문자로 구성됩니다.
    char* result = (char*)malloc(20 * sizeof(char));
    result[0] = '\0'; // 초기화 (빈 문자열)

    // 주어진 숫자를 로마 숫자로 변환하는 과정
    for (int i = 0; i < 13; i++) { // values 배열과 symbols 배열을 순회
        // 현재 값(values[i])이 num보다 작거나 같은 경우 반복적으로 처리
        while (num >= values[i]) {
            // 결과 문자열에 해당 로마 숫자(symbols[i]) 추가
            strcat(result, symbols[i]);
            // num에서 현재 값(values[i])을 빼기
            num -= values[i];
        }
    }
    return result; // 변환된 로마 숫자 문자열 반환
}

// 테스트용 메인 함수
int main() {
    int num1 = 3749;
    int num2 = 58;
    int num3 = 1994;

    // 테스트 케이스 실행 및 결과 출력
    printf("Input: %d, Output: %s\n", num1, intToRoman(num1)); // MMMDCCXLIX
    printf("Input: %d, Output: %s\n", num2, intToRoman(num2)); // LVIII
    printf("Input: %d, Output: %s\n", num3, intToRoman(num3)); // MCMXCIV

    return 0;
}
