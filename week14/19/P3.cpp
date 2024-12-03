#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        map<int, int> h;
        for (int i=nums2.size()-1; i>=0; i--) {
            if (i == nums2.size()-1) h[nums2[i]] = -1;
            else {
                if (nums2[i] < nums2[i+1]) h[nums2[i]] = nums2[i+1];
                else {
                    int iter = i;
                    while (iter < nums2.size()-1) {
                        h[nums2[i]] = -1;
                        if (nums2[i] < h[nums2[iter+1]]) {
                            h[nums2[i]] = h[nums2[iter+1]];
                            break;
                        }
                        iter += 1;
                    }
                }
            }
        }
        for (int j=0; j<nums1.size(); j++) answer.push_back(h[nums1[j]]);
        return answer;
    }
};

int main() {
    Solution result;
    vector<int> nums1 = {3,1,2,4};
    vector<int> nums2 = {3,1,2,4};
    vector<int> answer1 = result.nextGreaterElement(nums1, nums2);
    for (int i=0; i<answer1.size(); i++) {
        cout << answer1[i] << " ";
    }
    cout << endl;
    vector<int> nums3 = {1,3,5,2,4};
    vector<int> nums4 = {5,6,4,3,2,1,7};
    vector<int> answer2 = result.nextGreaterElement(nums3, nums4);
    for (int i=0; i<answer2.size(); i++) {
        cout << answer2[i] << " ";
    }
    cout << endl;
    return 0;
}