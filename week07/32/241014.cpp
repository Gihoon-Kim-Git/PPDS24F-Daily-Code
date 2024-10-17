#include <vector>

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return {1};
        } else if (rowIndex == 1) {
            return {1,1};
        } else {
            vector<int> previous = getRow(rowIndex-1);
            vector<int> current = {1};
            for (int i=1; i < previous.size(); i++) {
                current.push_back(previous[i] + previous[i-1]);
            }
            current.push_back(1);
            return current;
        }
    }
};