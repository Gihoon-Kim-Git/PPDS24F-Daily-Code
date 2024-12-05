#include <iostream>
#include <vector>
#include <limits>
using namespace std;


class Solution {
    public:
        vector<int> pancakeSort(vector<int>& arr) {
            vector<int> result;
            pancakeSortHelper(arr, result);
            cout << "REULST_____\n"; printVec(result); 
            return result;
        }

        int findMaxIdx(vector<int>& arr) {
            int max = -INT_MAX; int maxIdx = -1;
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] > max) {
                    max = arr[i]; maxIdx = i;
                }
            }
            return maxIdx;
        }

        void flipVec(vector<int>& arr, int k) {  //index k에서 flip하는거임
            int n = arr.size(); int i = 0; int j = k;
            while (i <= j) {
                swap(arr[i], arr[j]); i++; j--;
            }
        }

        void printVec(vector<int>& arr) {
            for (int ele: arr) {
                cout << ele << " ";
            }
            cout << endl;
        }

        void pancakeSortHelper(vector<int>& unsortedarr, vector<int>& result) {
        //max가 끝에 위치하게되면 그거 pop_back()하고 unsortedarr를 계속 이어가는거지
        int n = unsortedarr.size(); cout << n << ": "; printVec(unsortedarr);
        int maxIdx = findMaxIdx(unsortedarr);
            if (n == 0) {
                return;
            } 

            else if (n-1 == maxIdx) {
                unsortedarr.pop_back();
                // printVec(new_unsortedarr);                
                pancakeSortHelper(unsortedarr, result);
            } else {
            //max가 끝이 되게 하는법 (1). maxIdx에서 한번 flip하고, (2). 맨 마지막  idx에서 flip하고.
                flipVec(unsortedarr, maxIdx); result.push_back(maxIdx +1); //k개념이 여기서 index+1이라고 생각하면 되거든. 
                flipVec(unsortedarr, n-1); result.push_back(n-1 +1);
                pancakeSortHelper(unsortedarr, result);
            }
        }
};

int main() {

Solution mysol;
// Example 1:

vector<int> arr1 = {3,2,4,1}; // Output: [4,2,4,3]

// mysol.flipVec(arr1, 2); mysol.printVec(arr1);
// mysol.flipVec(arr1, 3); mysol.printVec(arr1); 
mysol.pancakeSort(arr1); 
// Explanation: 
// We perform 4 pancake flips, with k values 4, 2, 4, and 3.
// Starting state: arr = [3, 2, 4, 1]
// After 1st flip (k = 4): arr = [1, 4, 2, 3]
// After 2nd flip (k = 2): arr = [4, 1, 2, 3]
// After 3rd flip (k = 4): arr = [3, 2, 1, 4]
// After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted.

// Example 2:
vector<int> arr2 = {1,2,3}; // Output: []
// Explanation: The input is already sorted, so there is no need to flip anything.
// Note that other answers, such as [3, 3], would also be accepted.


    return 0;
}

// 3 2 4 1 : 1에서flip해서 ->
// 1 4 2 3 : 4에서flip해서 ->
// 4 1 2 3 : 3
// 3 2 1 4 : 1
// 제일 큰걸 오른쪽으로 밀고. 그 다음에 그 작은거에서 계속 recursively하면 되지 않을까.

// 2개만 있을떄.
// min, max로 

// 3개만 있을때.
// 젤큰걸 오른쪽으로 보내고
// 2개
