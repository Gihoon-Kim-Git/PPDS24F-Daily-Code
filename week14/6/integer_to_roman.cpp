#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string intToRoman(int num) {
    string Roman = "";
    vector<pair<int, string>> storeIntRoman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"}};
    for (int i = 0; i < storeIntRoman.size(); i++) {
      while (num >= storeIntRoman[i].first) {
        Roman += storeIntRoman[i].second;
        num -= storeIntRoman[i].first;
      }
    }
    return Roman;
  }
};