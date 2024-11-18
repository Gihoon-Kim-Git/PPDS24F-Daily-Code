class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> temp(rows, vector<int>(cols,0));
        int maxi = 0;

        for(int i = 0; i<rows; i++){
            for(int j = 0; j <cols; j++){
                if(matrix[i][j] == '1'){
                    if(i==0||j==0){
                        temp[i][j] = 1;
                    }
                    else{
                        temp[i][j] = min({temp[i-1][j], temp[i][j-1], temp[i-1][j-1]}) +1;
                    }
                    maxi = max(maxi, temp[i][j]);
                }
            }
        }
        return maxi*maxi;
    }
};