#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int findrow = 0;
        int findcol = 0;

        if(m==1){
            for(int j=0; j<n; j++){
                // cout<<matrix[i][j]<<" ";
                if (matrix[0][j] != target) continue;
                else if(matrix[0][j] == target) return true;
            }
        }

        else{
            // cout<<"findrow: "<<findrow<<endl;
            for(int i=0; i<m; i++){
                if (matrix[i][0]==target) return true;
                else if (matrix[i][0]<target){
                    for(int j=0; j<n; j++){
                        // cout<<matrix[i][j]<<" ";
                        if (matrix[i][j] == target) return true;
                    }
                }
            }
        }
        // cout<<matrix[findrow][findcol]<<endl;

        return false;
    }
};

// int main(void){
//     vector<vector<int>> matrix = {{5},{6}};
//     int target = 6;
//     Solution sol;
//     cout << sol.searchMatrix(matrix, target) << endl;
// }

// int main(void){
//     vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
//     int target = 5;
//     Solution sol;
//     cout << sol.searchMatrix(matrix, target) << endl;
// }