#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // We'll use a stack and a hashmap:
        // The stack will be used to find the next greater element for each element in nums2.
        // The hashmap (or unordered_map) will map each element in nums2 to its next greater element.
        
        unordered_map<int, int> nextGreater;
        stack<int> st;
        
        // Traverse nums2 from right to left (or left to right using a different logic)
        // Here we go from left to right:
        for (int num : nums2) {
            // Pop smaller or equal elements from the stack
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }
            
            // If stack is empty, no greater element to the right
            nextGreater[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        
        // Now build the result for nums1 using the precomputed map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        
        return result;
    }
};