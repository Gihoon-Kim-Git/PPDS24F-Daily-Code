#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1, 1);
        for (int i=1; i<rowIndex; ++i) {
            result[i] = getRow(rowIndex-1)[i-1] + getRow(rowIndex-1)[i];
        }
        return result;
    }
};