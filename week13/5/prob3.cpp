#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int M = mat.size();
        // int N = mat[0].size();
        
        vector<tuple<int, int>> scores;

        for (int i=0; i<M; i++) {
            int cnt_curr = 0;
            for (int sold: mat[i]) {
                if (sold) cnt_curr += 1;
                else break;
            }
            scores.push_back(tuple<int,int>({cnt_curr, i}));
        }

        sort(scores.begin(), scores.end());

        vector<int> answer;
        for (int i=0; i<k; i++) {
            answer.push_back(get<1>(scores[i]));
        }
        return answer;
    }
};
