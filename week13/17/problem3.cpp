// You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

// A row i is weaker than a row j if one of the following is true:

// The number of soldiers in row i is less than the number of soldiers in row j.
// Both rows have the same number of soldiers and i < j.
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.


#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;    


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        vector<int> result;
        vector<pair<int, int>> soldiers;

        for (int r=0; r<mat.size(); r++){
            vector<int> row = mat[r];
            int soldier = accumulate(row.begin(), row.end(), 0);

            soldiers.push_back(make_pair(soldier, r));
        }

        // soldiers[0] 작은순, soldiers[1] 작은 순으로 정렬
        sort(soldiers.begin(), soldiers.end(), [](pair<int, int> a, pair<int, int> b){
            if (a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        for (int i=0; i<k; i++){
            result.push_back(soldiers[i].second);
        }

        return result;

        
        
    }
};