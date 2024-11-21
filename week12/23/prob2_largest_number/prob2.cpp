#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string largestNumber(vector<int>& nums) {
    vector<string> numStrs;
    for (int num : nums) {
        numStrs.push_back(to_string(num));
    }

    // Custom comparator
    sort(numStrs.begin(), numStrs.end(), [](const string& a, const string& b) {
        return a + b > b + a; // Sort based on concatenated order
    });

    // Join the numbers
    string result;
    for (const string& num : numStrs) {
        result += num;
    }

    // Handle leading zeros
    if (result[0] == '0') return "0";

    return result;
}

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums) << endl; // Output: "9534330"
    return 0;
}
