#include <algorithm>
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main(){
    vector<int> vec = {5,12,6,100,1,0};
    auto it = max_element(vec.begin(),vec.begin()+4);
    int dist = distance(vec.begin(),it);
    cout << dist << endl;
    cout << vec[dist] << endl;
}

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;

        while(n>1){
            auto max_it = max_element(arr.begin(),arr.begin()+n);
            int dist = distance(arr.begin(),max_it);

            if(dist == n-1){
                n--;
                continue;
            }
            if(dist!=0){
                ans.push_back(dist+1);
                reverse(arr.begin(),arr.begin()+dist+1); // kick point, 이런식으로 begin,end 쓸 때는 항상 뒤에 범위에 하나 더 +1 한다고 생각하자.
            }
            ans.push_back(n);
            reverse(arr.begin(),arr.begin()+n);
            n--;
        }
        return ans;
    }
};