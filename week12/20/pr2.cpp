#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        // make thnem to string
        vector<string> vec;
        for(const int x : nums){
            vec.push_back(to_string(x));
        }

        while(!vec.empty()){
            string temp = vec[0];
            for(const string y: vec){
                if(y+temp > temp+y) temp = y;
            }
            ans += temp;
            auto it = find(vec.begin(),vec.end(),temp);
            vec.erase(it);
        }
        return ans[0]=='0' ? "0" : ans;
    }
};

// int main(){

//     string t1 = "31";
//     string t2 = "300";
//     if(t1>t2) cout << t1;
//     else cout << t2;
// }