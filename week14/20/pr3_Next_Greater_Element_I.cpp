using namespace std;
#include "vector"
#include <stack>
#include <map>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        map<int,int> m;
        
        for(int i=nums2.size()-1;i>=0;i--){
            int temp = nums2[i];
            while(!s.empty() && temp > s.top()){
                s.pop();
            }
            if(s.empty()) m[temp] = -1;
            else m[temp] = s.top();
            s.push(temp);
        }
        for(int j=0;j<nums1.size();j++){
            nums1[j] = m[nums1[j]];
        }
        return nums1;
    }
};