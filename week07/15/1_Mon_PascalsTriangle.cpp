#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        else if (rowIndex == 1) return {1, 1};
        else {
            vector<int> ans(rowIndex+1, 1);
            vector<int> prev = getRow(rowIndex-1);
            for(int i=1;i<rowIndex;i++) ans[i] = prev[i-1] + prev[i];
            return ans;
        }
    }
};