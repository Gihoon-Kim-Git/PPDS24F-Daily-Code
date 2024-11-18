/*Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.*/

/*수도코드
1. 필요 변수 초기화 : cur_prefix = strs[0]
2. strs의 두 번째요소부터 끝까지 차례로 이동하면서, 하나씩 cur_prefix와 비교해서 cur_prefix 갱신
    갱신하는 논리는, cur_prefix와 strs[i]를 비교하면서 글자가 같은 만큼의 길이 구함.
    cur_prefix[j] == strs[i][j] 이면 j++.(주의: j가 더 짧은 거 길이를 넘어가면 안됨.)
    cur_ prefix를  cur_prefix[0:j]로 갱신
3. return cur_prefix
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_len 200

char* longestCommonPrefix(char** strs, int strsSize) {
    char* cur_prefix = (char*)malloc(sizeof(char) * (max_len+1));

    //strs[0]을 cur_prefix로.
    int i = 0;
    while (strs[0][i] != '\0') {
        cur_prefix[i] = strs[0][i];
        i++;
    }
    cur_prefix[i] = '\0';

    for (int j = 0; j < strsSize; j++){
        int new_len = 0;
        while (cur_prefix[new_len] != '\0' && strs[j][new_len] != '\0' && cur_prefix[new_len] == strs[j][new_len]) new_len++;
        cur_prefix[new_len] = '\0';  // 이걸로 조정함! ^0^
    }

    return cur_prefix;
}