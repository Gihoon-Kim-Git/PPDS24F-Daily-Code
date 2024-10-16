#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int idx = 0;
        for(int i=0;i<m;i++){
            if(matrix[i][0]>target) break;
            idx++;
        }
        if(idx==0) return false;
        for(int j=0;j<idx;j++){
            int left = 0;
            int right = n-1;
            while(left<=right){
                int mid = (left+right)/2;
                if(matrix[j][mid]==target) return true;
                else if(matrix[j][mid] < target) left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
};