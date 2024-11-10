#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // each number = the sum of the two numbers directly above it 
        // given rowIndex -> return the vector<int> row 
        // index starts from 0
        /*
        1 (v)
        1 1 (v)
        1 2 1 
        1 3 3 1
        1 4 6 4 1
        1 5 10 10 5 1
        */
        // base case
        if (rowIndex==0 || rowIndex==1) {
            vector<int> ans(rowIndex+1, 1);
            return ans;
        }
        // memoization 
        vector<int> prev(rowIndex);  //
        vector<int> ans(rowIndex+1, 1);
        prev = getRow(rowIndex-1); // 한사이즈가 부족한 벡터가 리턴이된다. 

        for (int idx=1; idx<rowIndex; idx++) {
            ans[idx]=prev[idx-1]+prev[idx];
        }
        return ans;
    }
};