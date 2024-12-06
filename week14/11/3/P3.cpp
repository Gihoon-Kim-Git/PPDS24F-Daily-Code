#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> nextGreater;  // Map to store the next greater element for each element in nums2
        
        // Traverse nums2 and fill the nextGreater map
        for (int i = 0; i < nums2.size(); ++i) {
            while (!st.empty() && st.top() < nums2[i]) {
                nextGreater[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        // Traverse nums1 and get the next greater element from the map
        for (int num : nums1) {
            if (nextGreater.find(num) != nextGreater.end()) {
                ans.push_back(nextGreater[num]);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }

private:
    stack<int> st;  // Stack for maintaining the elements to find the next greater element
};

int main() {
    Solution solution;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = solution.nextGreaterElement(nums1, nums2);
    
    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
