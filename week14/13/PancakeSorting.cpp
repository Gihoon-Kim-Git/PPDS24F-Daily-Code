class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res; // To store the sequence of flips
        int n = arr.size();
        
        for (int size = n; size > 1; --size) {
            // Find the index of the largest element in the unsorted portion
            int max_index = max_element(arr.begin(), arr.begin() + size) - arr.begin();
            
            // If the largest element is not already at the correct position
            if (max_index != size - 1) {
                // Flip to bring the largest element to the front
                if (max_index != 0) {
                    res.push_back(max_index + 1);
                    reverse(arr.begin(), arr.begin() + max_index + 1);
                }
                // Flip to bring the largest element to its correct position
                res.push_back(size);
                reverse(arr.begin(), arr.begin() + size);
            }
        }
        
        return res;
    }
};





// 파이썬

// def pancakeSort(arr):
//     res = []
//     n = len(arr)
//     for size in range(n, 1, -1):
//         # Find the index of the largest element in the unsorted portion
//         max_index = arr.index(max(arr[:size]))
//         if max_index != size - 1:
//             # Flip to bring the largest element to the front
//             if max_index != 0:
//                 res.append(max_index + 1)
//                 arr[:max_index + 1] = reversed(arr[:max_index + 1])
//             # Flip to bring the largest element to its correct position
//             res.append(size)
//             arr[:size] = reversed(arr[:size])
//     return res
