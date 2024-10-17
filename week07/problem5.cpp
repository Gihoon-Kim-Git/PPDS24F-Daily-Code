class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n= matrix[0].size();
        cout<<n<<" "<<m<<endl;
        int y=m-1; int x= 0;
        while(x<n && y>-1){
            if(matrix[y][x]==target) return true;
            else if(matrix[y][x]>target){
                y--;
            }
            else{
                x++;
            }
        }
        return false;
    }
};