#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string intToRoman(int num) {
        // Creating vector for lookup
        std::vector<std::pair<int, std::string>> num_map = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        std::string result = "";
        
        // Loop through the values
        for (auto& pair : num_map) {
            while (num >= pair.first) {
                result += pair.second;
                num -= pair.first;
            }
        }

        return result;
    }
};
