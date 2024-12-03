#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rowStrength;

        for (int i = 0; i < mat.size(); ++i) {
            int soldiers = count(mat[i].begin(), mat[i].end(), 1); // soldiers calculation
            rowStrength.push_back({soldiers, i}); // {soldiers, row index}
        }

        sort(rowStrength.begin(), rowStrength.end());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(rowStrength[i].second);
        }

        return result;
    }
};

int main(void) {
    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    return 1;
}