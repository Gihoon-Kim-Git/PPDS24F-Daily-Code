#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
using namespace std;

// 전략
// 조건대로 sort를 한다~~ custom_sort & comparator & lambda 함수로
// 이어붙여서 string으로 출력한다. 

class Solution {
    public:


////////////////////////////////////
        void print1dVecInt(vector<int>& nums) {
            for (int i = 0; i < nums.size(); i++) { cout<< nums[i] << " ";}
            cout << endl;
        }
        void print1dVecStr(vector<string>& nums) {
            for (int i = 0; i < nums.size(); i++) { cout<< nums[i] << " ";}
            cout << endl;
        }

        vector<string> intVec_strVec(vector<int>& nums) {
            vector<string> strvec(nums.size());
            for (int i = 0; i < nums.size(); i++) {  strvec[i] = to_string(nums[i]);}
            return strvec;
        }

/////////SORT/////////////

        void custom_sort(vector<string>& strVec, function<bool(string, string)> comparator) {
            sort(strVec.begin(), strVec.end(), comparator);
        }
        bool descendFirst(string strA, string strB) {
            if (strA+strB > strB+strA) {
                // cout << strA+strB  << ">" << strB+strA << endl;
                return true; //strA가 먼저 오는게 맞으면 true;
            } else {
                return false;
            }
        }
////////////////////////////////////

        string largestNumber(vector<int>& nums) {
            
            //(1). vector<int> => vector<string> 변환
            vector<string> strvec = intVec_strVec(nums);
            // print1dVecStr(strvec);
            
            //(2). 내 기준대로 sort! (흐 넘 잘했다. )
            custom_sort(strvec, [this](string a, string b){return descendFirst(a, b);}); //solution 안이 들어와 있는 멤버여서!! this 필요 
            // print1dVecStr(strvec);

            //(3). 원소들 합쳐서 하나의 긴 string으로
            string result;
            for (string s: strvec) { result += s;}

            //(4). 단 모든 str이 0이라면, 즉 가장 큰 숫자가 0이라면 000000000일케돼있으면 0을 뱉어야됨
            if (result[0] == '0') { return "0";}
            return result;
        }
};

int main() {

    vector<int> nums1 = {0, 0, 0};
    vector<int> nums2 = {3, 30, 34, 5, 9};
    vector<int> nums3 = {34, 34, 10000, 5, 99, 9};
    vector<int> nums4 = {3,30,34,5,9};
    Solution mysol;
    cout << mysol.largestNumber(nums1);
    // mysol.descendFirst("30","3");
    return 0;
}