#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int, int>> strengths;  // (strength, index)

    for (int i = 0; i < mat.size(); ++i) {
        int soldier_count = count(mat[i].begin(), mat[i].end(), 1);  // Count 1's
        strengths.push_back({soldier_count, i});
    }

    // Sort by strength and index
    sort(strengths.begin(), strengths.end());

    // Extract the indices of the k weakest rows
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(strengths[i].second);
    }
    return result;
}

int main() {
    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    int k = 3;
    vector<int> result = kWeakestRows(mat, k);
    for (int idx : result) {
        cout << idx << " ";
    }
    // Output: 2 0 3
    return 0;
}
