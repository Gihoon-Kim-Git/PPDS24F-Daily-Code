class Solution {
public:

    bool isSorted(const vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;
        return true;
    }

    vector<int> pancakeSort(vector<int>& arr) {
        
        int end = arr.size();
        vector<int> res;

        while (!isSorted(arr)) {
            int maxIndex = 0;
            int maxValue = arr[0];

            for (int i = 1; i < end; i++) {

                if (maxValue < arr[i]) {
                    maxValue = arr[i];
                    maxIndex = i;
                }
            }
            reverse(arr.begin(), arr.begin() + maxIndex + 1);
            res.push_back(maxIndex + 1);
            reverse(arr.begin(), arr.begin() + end);
            res.push_back(end);
            end--;
        }
        return res;
        
    }
};