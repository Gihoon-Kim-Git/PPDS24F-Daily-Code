class Solution {
public:
    //재귀로 시도했으나 시간 초과
    // int getvalue(int row, int col){
    //     if(col==0)
    //     {
    //         return 1;
    //     }
    //     else
    //     {
    //         return getvalue(row-1, col-1) + getvalue(row-1, col);
    //     }  
    // };

    // vector<int> getRow(int rowIndex) {
    //     vector<int> ans(rowIndex+1);

    //     for(int i=0; i<=rowIndex; i++)
    //     {
    //         if(i<=rowIndex/2)
    //         {
    //             ans[i]=getvalue(rowIndex, i);
    //         }
    //         else
    //         {
    //             ans[i]=ans[rowIndex-i];
    //         }
    //     }

    //     return ans;
        
    // }
    
    //한번 계산한 걸 그대로 사용하는 방법을 써보자 memoization
    std::vector<vector<int>> memo;
    
    int val(int x, int y){
        if(y==0 || x==y){
            memo[x][y]=1;
            return memo[x][y];
        }
        else
        {
            //memo기법에서 중요한 부분! 이미 계산한 부분인지 아닌지 확인하기
            if(memo[x][y]!=-1){
                return memo[x][y];
            }

            memo[x][y]=val(x-1, y-1)+val(x-1, y);
            return memo[x][y];
        }
        
    }
    
    vector<int> getRow(int rowIndex){
        memo.resize(rowIndex+1, vector<int>(rowIndex+1, -1));
        
        for (int i=0; i<=rowIndex; i++){
            memo[rowIndex][i]=val(rowIndex, i);
        }

        return memo[rowIndex];
    }

};
