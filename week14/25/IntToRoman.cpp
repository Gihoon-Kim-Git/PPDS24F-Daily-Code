#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Pairs of integer values and their corresponding Roman numerals, 
        // including the subtractive cases.
        vector<pair<int,string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result;
        // Greedily match the largest Roman numeral values to 'num'
        for (auto &entry : romanMap) {
            while (num >= entry.first) {
                result += entry.second;
                num -= entry.first;
            }
        }
        return result;
    }
};