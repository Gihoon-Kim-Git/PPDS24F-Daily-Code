#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        std::vector<std::pair<int, int>> cnt; // {군인 수, 행 번호}
        
        // 각 행의 군인 수 계산
        for (int i = 0; i < mat.size(); i++) {
            int soldiers = std::count(mat[i].begin(), mat[i].end(), 1); // 군인 수 세기
            cnt.push_back({soldiers, i}); // 군인 수와 행 번호 저장
        }
        
        // 군인 수와 인덱스를 기준으로 정렬
        std::sort(cnt.begin(), cnt.end());
        
        // 상위 k개의 약한 행 추출
        std::vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(cnt[i].second); // 행 번호 추가
        }
        
        return result;
    }
};