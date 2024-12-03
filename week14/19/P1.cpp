#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string answer = "";
        vector<string> roman_s = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> roman_i = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        while (num > 0) {
            for (int r=0; r<13; r++) {
                if (num >= roman_i[r]) {
                    answer.append(roman_s[r]);
                    num -= roman_i[r];
                    break;
                }
            }
        }
        return answer;
    }
};

int main() {
    Solution result;
    int num1 = 3749;
    cout << result.intToRoman(num1) << endl;
    int num2 = 58;
    cout << result.intToRoman(num2) << endl;
    int num3 = 1994;
    cout << result.intToRoman(num3) << endl;

    return 0;
}