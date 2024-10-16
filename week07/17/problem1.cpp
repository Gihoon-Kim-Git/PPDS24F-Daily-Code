// week 07

// Monday. [Pascal's triangle](https://leetcode.com/problems/pascals-triangle-ii/description/)


// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:

// Input: rowIndex = 3
// Output: [1,3,3,1]
// Example 2:

// Input: rowIndex = 0
// Output: [1]
// Example 3:

// Input: rowIndex = 1
// Output: [1,1]
 

// Constraints:

// 0 <= rowIndex <= 33

#include <vector>

using namespace std;


class Solution {

public:

    vector<int> prevRow = {1};
    vector<int> currRow;

    vector<int> getRow(int rowIndex) {

        if (rowIndex == 0){
            return {1};
        } else{
            for (int i = 1; i <= rowIndex; i++){
                currRow = {1};
                for (int j = 1; j < i; j++){
                    currRow.push_back(prevRow[j - 1] + prevRow[j]);
                }
                currRow.push_back(1);
                prevRow = currRow;
            }
        }

        return currRow;

        // for (int i = 0; i <= rowIndex; i++){
        //     result.push_back(getNum(rowIndex, i));
        // }
        
        
    }

    // int getNum(int rowIndex, int idx){
    //     // recursive -> time limit exceeded
    //     if (idx == 0 || idx == rowIndex){
    //         return 1;
    //     } 

    //     return getNum(rowIndex - 1, idx - 1) + getNum(rowIndex - 1, idx);
    // }
};