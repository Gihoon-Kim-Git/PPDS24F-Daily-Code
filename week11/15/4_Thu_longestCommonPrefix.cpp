#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonprefix = "";
        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs[strs.size()-1];
        for (int i=0; i < min(first.size(), last.size()); i++){
            if (first[i] != last[i]) return commonprefix;
            commonprefix += first[i];    
        }
        return commonprefix;
    }
};