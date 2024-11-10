//방법1

#include <vector>
#include <algorithm>

class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int cnt[3] = {0, 0, 0};
        
        // 돌의 나머지를 구해서 개수를 셉니다.
        for (int s : stones) {
            cnt[s % 3]++;
        }

        if (cnt[0] % 2 == 0) { // 나머지 0의 개수가 짝수일 때
            // 나머지 1이나 2가 없으면 Alice는 이길 수 없습니다.
            if (cnt[1] == 0 || cnt[2] == 0) {
                return false;
            } else {
                return true; // 나머지 1과 2가 둘 다 충분히 있으면 Alice가 유리합니다.
            }
        } else { // 나머지 0의 개수가 홀수일 때
            return abs(cnt[1] - cnt[2]) >= 3; // 한쪽이 3개 이상 많으면 Alice가 유리합니다.
        }
    }
};

//방법2 
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        // 돌의 나머지를 구해서 개수를 셉니다.
        for (int s : stones) {
            cnt[s % 3]++;
        }

        // 나머지 1이나 나머지 2 중 하나가 없는 경우
        if (std::min(cnt[1], cnt[2]) == 0) {
            return std::max(cnt[1], cnt[2]) > 2 && cnt[0] % 2 == 1;
        }

        // 나머지 1과 나머지 2가 모두 있는 경우
        return std::abs(cnt[1] - cnt[2]) > 2 || cnt[0] % 2 == 0;
    }
};