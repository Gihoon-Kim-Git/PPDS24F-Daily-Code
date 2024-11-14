#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        return helper(s, 0, s.length()-1);
    }

    bool helper(const string& s, int i, int j) {
        // 끝까지 무사 통과
        if (i >= j) {
            return true;
        }
        // 앞 letter 가 non-alnum : skip
        else if (!isalnum(static_cast<unsigned char>(s[i]))) {
            return helper(s, i+1, j);
        }
        // 뒤 letter 가 non-alnum : skip
        else if (!isalnum(static_cast<unsigned char>(s[j]))) {
            return helper(s, i, j-1);
        }
        // 앞뒤 letter 가 모두 alnum - 동일성 체크 - 불일치 : return false
        else if (tolower(static_cast<unsigned char>(s[i])) != tolower(static_cast<unsigned char>(s[j]))) {
            return false;
        }
        // 앞뒤 letter 가 모두 alnum - 동일성 체크 - 일치 : 다음 단계 검사
        else {
            return helper(s, i+1, j-1);
        }
    }
};
