#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre = {1};
        if(rowIndex == 0){return pre;}

        for(int n=1; n<=rowIndex; n++){
            vector<int> cur;
            for(int i=0; i<=n; i++){
                int leftParent = i-1;
                int rightParent = i;
                if((leftParent<0) or (rightParent>=pre.size())){
                    cur.push_back(1);
                }
                else{
                    cur.push_back(pre[leftParent] + pre[rightParent]);
                }
            }
            pre = cur;
        }
        return pre;
    }
};