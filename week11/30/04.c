#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";  // 배열이 비었을 경우 빈 문자열 반환

    // 첫 번째 문자열을 기준으로 시작
    char* prefix = strs[0];

    // 두 번째 문자열부터 하나씩 비교
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        // 두 문자열의 공통 접두사 길이를 계산
        while (strs[i][j] == prefix[j] && j < strlen(prefix)) {
            j++;
        }
        // 공통 접두사가 발견되면 prefix를 그 길이만큼 잘라서 갱신
        prefix[j] = '\0';
    }

    return prefix;
}

int main() {
    char* strs1[] = {"flower", "flow", "flight"};
    int size1 = 3;
    printf("Longest Common Prefix: %s\n", longestCommonPrefix(strs1, size1));

    char* strs2[] = {"dog", "racecar", "car"};
    int size2 = 3;
    printf("Longest Common Prefix: %s\n", longestCommonPrefix(strs2, size2));

    return 0;
}
