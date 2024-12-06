#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    char* answer = (char*)malloc(100 * sizeof(char));
    char* roman_s[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int roman_i[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int index = 0;
    while (num > 0) {
        for (int r=0; r<13; r++) {
            if (num >= roman_i[r]) {
                for (int i=0; i<strlen(roman_s[r]); i++) {
                    answer[index++] = roman_s[r][i];
                }
                num -= roman_i[r];
                break;
            }
        }
    }
    answer[index++] = '\0'; // 마지막 종료 문자를 포함시켜야 함
    return answer;
}

int main() {
    int num1 = 3749;
    printf("%s\n", intToRoman(num1));

    int num2 = 58;
    printf("%s\n", intToRoman(num2));

    int num3 = 1994;
    printf("%s\n", intToRoman(num3));

    return 0;
}