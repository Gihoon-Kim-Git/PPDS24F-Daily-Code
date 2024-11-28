#include<numeric>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n_row = mat.size();
        // 각 row_num과 soldier의 합을 저장할 변수 선언
        vector<pair<int, int>> soldier;
        int i = 0;
        for(vector<int> n : mat){
            soldier.push_back({i, accumulate(n.begin(), n.end(), 0)});
            i++;
        }
        // value값을 기준으로 key값을 sorting
        sort(soldier.begin(), soldier.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if(a.second != b.second){
                return a.second < b.second; // 값 기준 오름차순 정렬(내림차순은 > 사용)
            }else{
                return a.first < b.first;  // 만일 값이 같다면 row 순서대로 정렬
            }
            
        });
        // sorting 순서대로 기록
        vector<int> result;
        int j = 0;
        for(const pair<int, int>& num : soldier){
            if(j < k){
                result.push_back(num.first);
                j++;
            }
        }
        return result;
    }
};