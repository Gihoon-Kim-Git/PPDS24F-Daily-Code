class Solution {
public:
    string intToRoman(int num) {
        // Define Roman numeral symbols and their values
        vector<pair<int, string>> romanSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string result = "";

        // Iterate through the symbols
        for (auto& [value, symbol] : romanSymbols) {
            while (num >= value) {
                result += symbol; // Append the Roman numeral
                num -= value;     // Reduce the number
            }
        }

        return result;
    }
};
