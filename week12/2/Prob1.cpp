#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // 각 char와 그 출현 횟수를 저장할 변수를 선언
        vector<pair<char, int>> fsort;
        for(char ch : s){
            auto it = find_if(fsort.begin(), fsort.end(), [ch](const pair<char, int>& p){
                return p.first == ch;
            });
            if(it != fsort.end()){
                it->second++;
            }else{
                fsort.push_back({ch, 1});
            }
        }

        // value값을 기준으로 key값을 sorting
        sort(fsort.begin(), fsort.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; // 값 기준 내림차순 정렬(오름차순은 < 사용)
        });
        // sorting순서대로, 출현횟수만큼 key값을 연속적으로 기록
        string result = "";
        for(const pair<char, int>& ch : fsort){
            for(int i=0; i<ch.second; i++){
                result += ch.first;
            }
        }
        return result;

    }
};