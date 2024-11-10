#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = vector<int>(rowIndex+1, 1);
        int temp = 1;
        for (size_t i=0; i<=rowIndex; i++) {
            for (size_t j=1; j<i; j++) {
                row.at(j) += temp;
                temp = row.at(j) - temp;
            }
        }
        return row;
    }
};
