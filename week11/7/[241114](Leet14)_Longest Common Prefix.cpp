/*수도코드
1. 필요 변수 초기화 : cur_prefix = strs[0]
2. strs의 두 번째요소부터 끝까지 차례로 이동하면서, 하나씩 cur_prefix와 비교해서 cur_prefix 갱신
    갱신하는 논리는, cur_prefix와 strs[i]를 비교하면서 글자가 같은 만큼의 길이 구함.
    cur_prefix[j] == strs[i][j] 이면 j++.(주의: j가 더 짧은 거 길이를 넘어가면 안됨.)
    cur_ prefix를  cur_prefix[0:j]로 갱신
3. return cur_prefix
*/



#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cur_prefix = strs[0];
        for (int i = 0 ; i < strs.size(); i++){
            string shorter = cur_prefix.size() < strs[i].size()? cur_prefix : strs[i];
            int j = 0;
            while (cur_prefix[j] == strs[i][j] && j <= shorter.size()-1) j++;
            string new_prefix = cur_prefix.substr(0,j); //substr(시작인덱스, 길이)
            cur_prefix = new_prefix;
        }
        return cur_prefix;
    }
};