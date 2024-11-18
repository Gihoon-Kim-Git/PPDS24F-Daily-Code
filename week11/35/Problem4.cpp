/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    
    // 첫 번째 문자열을 초기 접두사로 설정
    string prefix = strs[0];
    
    // 나머지 문자열과 하나씩 비교
    for (int i = 1; i < strs.size(); i++) {
        // 현재 문자열과의 공통 접두사를 줄여가며 찾기
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1); // 접두사를 한 글자씩 줄임
            if (prefix.empty()) return "";
        }
    }
    
    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;
    return 0;
}
