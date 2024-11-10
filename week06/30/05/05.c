#include <stdio.h>
#include <string.h>

int maxNumberOfBalloons(char* text) {
    // 알파벳 26개의 빈도를 저장할 배열
    int freq[26] = {0};
    
    // 1. 문자열에서 각 문자의 빈도를 카운트
    for (int i = 0; text[i] != '\0'; i++) {
        freq[text[i] - 'a']++;
    }
    
    // 2. 필요한 문자 'b', 'a', 'l', 'o', 'n'의 빈도
    int count_b = freq['b' - 'a'];
    int count_a = freq['a' - 'a'];
    int count_l = freq['l' - 'a'] / 2;  // 'l'은 2번 필요
    int count_o = freq['o' - 'a'] / 2;  // 'o'도 2번 필요
    int count_n = freq['n' - 'a'];
    
    // 3. 만들 수 있는 'balloon'의 최대 개수는 이 5개 중 최소값
    int result = count_b;
    if (count_a < result) result = count_a;
    if (count_l < result) result = count_l;
    if (count_o < result) result = count_o;
    if (count_n < result) result = count_n;
    
    return result;
}

int main() {
    // 테스트 케이스
    char text1[] = "nlaebolko";
    char text2[] = "loonbalxballpoon";
    char text3[] = "leetcode";

    printf("sstring= '%s': result = %d\n", text1, maxNumberOfBalloons(text1));  // 출력: 1
    printf("sstring= '%s': result = %d\n", text2, maxNumberOfBalloons(text2));  // 출력: 2
    printf("sstring= '%s': result = %d\n", text3, maxNumberOfBalloons(text3));  // 출력: 0

    return 0;
}
