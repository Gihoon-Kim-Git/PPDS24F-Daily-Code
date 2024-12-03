#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> array;
        vector<int> answer;
        for (int i=0; i<mat.size(); i++) {
            array.push_back(make_pair(i, 0));
            for (int j=0; j<mat[i].size(); j++) {
                array[i].second += mat[i][j];
            }
        }
        sort(array.begin(), array.end(), compare);
        for (int i=0; i<k; i++) {
            answer.push_back(array[i].first);
        }
        return answer;
    }
};


int main() {
    Solution result;
    vector<vector<int>> mat1 = {{1,1,0,0,0},
                                {1,1,1,1,0},
                                {1,0,0,0,0},
                                {1,1,0,0,0},
                                {1,1,1,1,1}};
    vector<int> answer1 = result.kWeakestRows(mat1, 3);
    for (int i=0; i<answer1.size(); i++) {
        cout << answer1[i] << " ";
    }
    cout << endl;
    vector<vector<int>> mat2 = {{1,0,0,0},
                                {1,1,1,1},
                                {1,0,0,0},
                                {1,0,0,0}};
    vector<int> answer2 = result.kWeakestRows(mat2, 2);
    for (int i=0; i<answer2.size(); i++) {
        cout << answer2[i] << " ";
    }
    cout << endl;
    return 0;
}