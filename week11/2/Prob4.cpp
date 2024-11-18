#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = "";
        // sort strs
        sort(strs.begin(), strs.end()); 
        
        string first_str = strs[0];
        string last_str = strs[strs.size() - 1];

        for (int i=0; i< first_str.size(); i++) {
            if (first_str[i] == last_str[i])
                lcp += first_str[i];
            else
                break;
        }

        return lcp;
    }
};