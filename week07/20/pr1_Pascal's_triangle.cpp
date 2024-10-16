#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Using Dynamic Programming
        vector<int> ans(rowIndex+1,1);
        for(int i=1;i<rowIndex;i++){
            for(int j=i;j>0;j--){
                ans[j] += ans[j-1];
            }
        }
        return ans;
    }
};