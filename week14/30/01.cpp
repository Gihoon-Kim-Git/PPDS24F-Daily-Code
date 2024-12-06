#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;

// 전략
// - overloading해서 string 합/곱 할 수 있게 하고, 1000단위부터 더하면서 nunm에서는 빼깅!
// 0 IV = 4;
// 1 IX = 9;
// 2 XL = 40;
// 3 XC = 90;
// 4 CD = 400;
// 5 CM = 900;
// 6 I = 1;
// 7 V = 5;
// 8 X = 10;
// 9 L = 50;
// 10 C = 100;
// 11 D = 500;
// 12 M = 1000;

// + 연산자는 기본적으로 지원됨
// - 연산자: s1에서 s2의 모든 부분 문자열 제거
string operator-(const string& s1, const string& s2) {
    string result = s1;
    size_t pos = result.find(s2);
    while (pos != string::npos) {
        result.erase(pos, s2.length());
        pos = result.find(s2);
    }
    return result;
}

// * 연산자: 문자열을 n번 반복
string operator*(const string& s, int n) {
    if (n <= 0) return "";
    string result;
    result.reserve(s.length() * n); // 미리 메모리 예약
    for (int i = 0; i < n; ++i) {
        result += s;
    }
    return result;
}

class Solution {
    public:
        string intToRoman(int num) {
            // 1000이상 (XXXX)
            string result;
            if (num >= 1000) {
                int cnt3 = num / 1000;
                string M = "M";
                result += M * cnt3;
                num -= 1000 * cnt3;
            }
            // 100이상 (XXX)
            if (num >= 100) {
                int cnt2 = num / 100;
                if (cnt2 == 4) {
                    result += "CD";
                    num -= 400;
                } else if (cnt2 == 9) {
                    result += "CM";
                    num -= 900;
                } else if (cnt2 >= 5){
                    result += "D";
                    num -= 500;
                    if (num >= 100) {
                        int cnt2_2 = num / 100;
                        string C = "C";
                        result += C * cnt2_2;
                        num -= cnt2_2 * 100;
                    }
                } else {
                    string C = "C";
                    result += C * cnt2;
                    num -= cnt2 * 100;                    
                }
            }
            // 10이상 (XX)
            if (num >= 10) {
                int cnt1 = num / 10;
                if (cnt1 == 4) {
                    result += "XL";
                    num -=40;
                } else if (cnt1 == 9) {
                    result += "XC";
                    num -= 90;
                } else if (cnt1 >= 5){
                    result += "L";
                    num -= 50;
                    if (num >= 10) {
                        int cnt1_2 = num / 10;
                        result += string("X") * cnt1_2;
                        num -= cnt1_2 * 10;
                    }
                } else {
                    result += string("X") * cnt1;
                    num -= cnt1 * 10;                    
                }
            }
        
            // 1이상 (X)
            if (num >= 1) {
                int cnt0 = num / 1;
                if (cnt0 == 4) {
                    result += "IV";
                    num -=4;
                } else if (cnt0 == 9) {
                    result += "IX";
                    num -= 9;
                } else if (cnt0 >= 5){
                    result += "V";
                    num -= 5;
                    if (num >= 1) {
                        int cnt0_2 = num / 1;
                        result += string("I") * cnt0_2;
                        num -= cnt0_2 * 1;
                    }
                } else {
                    result += string("I") * cnt0;
                    num -= cnt0 * 1;                    
                }                
            }
        
        
            if (num == 0) {
                cout << "num = 0: WELL DONE" << endl;
            } else {
                cout << "something's wrong: " << num << endl;
            }
            return result;

        }
};


// if 4,9로 시작
// else max를 뽑아. 


int main() {
    int num1 = 3749; //Output: "MMMDCCXLIX"
    int num2 = 58; //Output: "LVIII"
    int num3 = 1994; //Output: "MCMXCIV"

    string empty;
    string A = "A";
    string B = "B";
    cout << A * 3 << endl;
    cout << A + B << endl;
    cout << empty + A + B << endl;

    Solution mysol;
    cout << mysol.intToRoman(num1) << endl;;
    cout << mysol.intToRoman(num2) << endl;;
    cout << mysol.intToRoman(num3) << endl;;
    return 0;
}

