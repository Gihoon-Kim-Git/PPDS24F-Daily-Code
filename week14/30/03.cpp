#include <iostream>
#include <vector>

using namespace std;

// 문제를 이해하자.
// nums1을 for문으로 순환하면서
// 걔를 num2에서 찾은다음
// nums2내에서 그 이후의 idx에서 걔보다 더 큰애가 나오면 그 큰애를 nums1의 idx에 넣고, 없으면 -1을 넣는당. 

class Solution {
    public:
        void printVec(vector<int> nums) {
            for (int i = 0; i < nums.size(); i++) {
                cout << nums[i] << " ";
            }
            cout << endl;
        }

        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//nums1 size랑 같은 vector를 만들고 -1로 초기화한다.
            int len1 = nums1.size(); int len2 = nums2.size();
            vector<int> result(len1, -1);
//for문 nums1에서 돌면서 nums2에서 찾으면 그 이후를 check.
            for (int i = 0; i < len1; i++) {
                int ele = nums1[i];
                cout << "\n"<<ele << "___________\n";
                for (int j = 0; j < len2; j++) {
                    if (nums2[j] == ele) {
                        cout << "found it! =>" << ele << "in index: " << j << " ||";
                        for (int k = j; k < len2; k++) {
                            if (nums2[k] > ele) {
                                cout << nums2[k] << " is greater.\n" << endl;
                                result[i] = nums2[k];
                                break;
                            }
                        }
                    }
                }
            }

            return result;
        }
};


int main() {

    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2}; //Output: [-1,3,-1]

    vector<int> NUMS1 = {2,4};
    vector<int> NUMS2 = {1,2,3,4}; // Output: [3,-1]


    Solution mysol;
    vector<int> result1= mysol.nextGreaterElement(nums1, nums2);
    vector<int> result2= mysol.nextGreaterElement(NUMS1, NUMS2);

    mysol.printVec(result1);
    mysol.printVec(result2);
    return 0;
}

