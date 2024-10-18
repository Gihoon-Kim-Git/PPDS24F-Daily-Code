class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //0,0부터 시작해서 row+1씩... 같거나 작을 동안
        //col+1씩... 같은게 나올동안
        
        for(size_t i=0; i<matrix.size(); i++){
            for(size_t j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]>target){
                    break;
                }
                else if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};

//칼럼의 사이즈를 측정할 때
//matrix[0].size()