class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater; // To store the next greater element for each number in nums2
        stack<int> s; // Monotonic stack to find the next greater elements

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];

            // Remove elements from the stack that are smaller than or equal to the current number
            while (!s.empty() && s.top() <= num) {
                s.pop();
            }

            // If the stack is not empty, the top of the stack is the next greater element
            nextGreater[num] = s.empty() ? -1 : s.top();

            // Push the current number onto the stack
            s.push(num);
        }

        // Prepare the result for nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
    }
};
