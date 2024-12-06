#include <vector>
#include <string>

using namespace std;


class Solution {
private:
    vector<string> symbols_one = {"I", "X", "C", "M"};
    vector<string> symbols_five = {"V", "L", "D", ""};

public:
    string intToRoman(int num) {
        // base case
        if (num==0) {
            return "";
        }

        // recursive case
        int first_digit = num;
        int exp = 0;
        int power10 = 1;
        while (first_digit >= 10) {
            first_digit /= 10;
            exp += 1;
            power10 *= 10;
        }
        int residue = num - first_digit * power10;

        if (first_digit == 4) {
            return symbols_one[exp] + symbols_five[exp] + intToRoman(residue);
        }
        else if (first_digit == 9) {
            return symbols_one[exp] + symbols_one[exp+1] + intToRoman(residue);
        }
        else if (first_digit < 5) {
            return string(first_digit, symbols_one[exp][0]) + intToRoman(residue);
        }
        else {  // first digit > 5
            return symbols_five[exp] + string(first_digit - 5, symbols_one[exp][0]) + intToRoman(residue);
        }
    }
};
