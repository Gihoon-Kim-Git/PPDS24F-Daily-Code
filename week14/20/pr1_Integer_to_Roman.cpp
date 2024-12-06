#include <vector>
using namespace std;
#include <string>
#include <tuple>
#include <stdexcept>

class Solution {
public:
    string intToRoman(int num) {

        vector<tuple<string,int>> m = {
            {"M",1000},
            {"CM",900},
            {"D",500},
            {"CD",400},
            {"C",100},
            {"XC",90},
            {"L",50},
            {"XL",40},
            {"X",10},
            {"IX",9},
            {"V",5},
            {"IV",4},
            {"I",1}
        };
        string ans = "";
        for(const auto pair : m){
            while(num >= get<1>(pair)){
                ans += get<0>(pair);
                num -= get<1>(pair);
            }
        }
        return ans;
    }
};