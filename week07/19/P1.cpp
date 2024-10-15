#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1, 1);
        for (int j=1; j<rowIndex; j++) {
            result[j] = getRow(rowIndex-1)[j-1] + getRow(rowIndex-1)[j];
        }
        return result;
    }
};

int main() {
    int rowIndex = 5;
    Solution result;
    vector<int> row = result.getRow(rowIndex);
    for (int i=0; i<rowIndex+1; i++) {
        cout << row[i] << " ";
    }
    cout << endl;

    return 0;
}