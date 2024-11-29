// You are given an m x n binary matrix `mat` of 1's (representing soldiers) and 0's (representing civilians).
// The soldiers are positioned in front of the civilians, meaning all the 1's appear to the left of all the 0's in each row.
//
// A row i is weaker than a row j if:
// - The number of soldiers in row i is less than the number of soldiers in row j.
// - Both rows have the same number of soldiers, and i < j.
//
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
//
// Example 1:
// Input: mat = [
//   [1, 1, 0, 0, 0],
//   [1, 1, 1, 1, 0],
//   [1, 0, 0, 0, 0],
//   [1, 1, 0, 0, 0],
//   [1, 1, 1, 1, 1]
// ], k = 3
// Output: [2, 0, 3]
//
// Example 2:
// Input: mat = [
//   [1, 0, 0, 0],
//   [1, 1, 1, 1],
//   [1, 0, 0, 0],
//   [1, 0, 0, 0]
// ], k = 2
// Output: [0, 2]
//
// Constraints:
// - 2 <= m, n <= 100
// - 1 <= k <= m
// - matrix[i][j] is either 0 or 1
#include <iostream>
#include <vector>
#include <algorithm> // Include this for std::count

using namespace std;

class Solution {
public:

    // helper function for custom swapping
    void swap(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); i++) {
            int temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        }
    }

    // custom bubble sort function
    void bubble_sort_custom(vector<vector<int>>& arr) {
        /**
         * Custom bubble sort function to sort rows based on:
         * - Soldier numbers (arr[][1]) in ascending order.
         * - Row indices (arr[][0]) in ascending order for ties.
         */
        int size = arr.size();
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j][1] > arr[j + 1][1] || 
                    (arr[j][1] == arr[j + 1][1] && arr[j][0] > arr[j + 1][0])) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int matSize = mat.size();
        vector<vector<int>> soldiers(matSize, vector<int>(2)); // Soldier array (row index and count)

        // Fill soldiers array
        for (int i = 0; i < matSize; i++) {
            soldiers[i][0] = i; // Row index
            // std::count(startIterator, endIterator, value being counted);
            soldiers[i][1] = count(mat[i].begin(), mat[i].end(), 1); // Count soldiers in the row
        }

        // Sort the soldiers array
        bubble_sort_custom(soldiers);

        // Prepare the result array
        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = soldiers[i][0]; // Store the row indices of the k weakest rows
        }

        return result;
    }
};

// Example test cases
void test_kWeakestRows() {
    Solution solution;

    vector<vector<int>> mat1 = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    int k1 = 3;
    vector<int> result1 = solution.kWeakestRows(mat1, k1);
    for (int x : result1) cout << x << " ";  // Output: 2 0 3
    cout << endl;

    vector<vector<int>> mat2 = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };
    int k2 = 2;
    vector<int> result2 = solution.kWeakestRows(mat2, k2);
    for (int x : result2) cout << x << " ";  // Output: 0 2
    cout << endl;
}

int main() {
    test_kWeakestRows();
    return 0;
}
