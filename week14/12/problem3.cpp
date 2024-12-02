class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (auto&it: nums1){
            bool added= false;
            bool location=false;
            for(auto&num:nums2){
                
                if(it==num){
                    location=true;
                }
                if(it<num&&location){
                    added=true;
                    ans.emplace_back(num);
                    break;
                }
            }
            if(!added){
                ans.emplace_back(-1);
            }
        }
        return ans;
    }
};