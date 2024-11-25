#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s = "APPLETREE";
    unordered_map<char,int> m;
    for(char ch : s){
        m[ch]++;
    }

    // for(const auto p : m){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }

    vector<pair<char,int>> vec(m.begin(),m.end());

    sort(vec.begin(),vec.end());
    // for(const auto x : vec){
    //     cout<<x.first<<" "<<x.second<<endl;
    // } // 일반 정렬 --> 효과 없음
    sort(vec.begin(),vec.end(),[](pair<char,int> &a,pair<char,int> &b){
        return a.second > b.second;
    });
    for(const auto x : vec){
        cout<<x.first<<" "<<x.second<<endl;
    }
    string ans;
    for(auto p : vec){
        ans.append(p.second,p.first);
    }
    cout << ans << endl;
    // string temp = "";
    // temp += 'b';
    // temp += "cd";
    // temp += string(5,'z');
    // cout << temp;
}