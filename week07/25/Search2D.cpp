#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); int n = matrix[0].size();
        bool answer = false;
        for (int i=0; i<m; ++i) {
            int start = 0; int end = n-1; int middle = m/2;
            cout << i << endl;
            while (start<=end) {
                if (matrix[i][middle]==target) {answer = true; return answer;}
                else if (matrix[i][middle]>target) {
                    end = middle-1;
                    middle = (start+end)/2;
                }
                else {
                    start = middle+1;
                    middle = (start+end)/2;
                }
            }
        }
        return answer;
    }
};

int main(void) {
    vector<vector<int>> matrix = {{1,4,7,11,15},
                                {2,5,8,12,19},
                                {3,6,9,16,22},
                                {10,13,14,17,24},
                                {18,21,23,26,30}}; 
    int target = 5;
    Solution a;
    int result =a.searchMatrix(matrix, target);
    cout << result << endl;
    return 1;
}