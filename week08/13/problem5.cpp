class Solution {
public:
    int findMin(vector<int>& nums) {
        //이전값보다 작아지면 무조건 걔가 가장 작은 값
        
        for(auto i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                return nums[i+1];
            }
        }
        return nums[0];
    }
};