/*Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.
 */

/*Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109*/

/* 아이디어
    1. 숫자가 아닌 문자열로 두고 내림차순 정렬
    2. 내림차순 정렬할 때, x+y, y+x 를 비교해서 정렬하도록. sort 함수 정의
*/


#include <algorithm>
#include <string>
#include <vector>
using namespace std;


bool cmp(const string& a, const string& b){
    return a+b > b+a;  //이건 내림차순 정렬. 
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //1) 모든 nums의 요소를 string으로 바꿔준다.
        // for (int i = 0; i < nums.size(); i++){
        //     nums[i] = to_string(nums[i]); // 이렇게 하면 오류 발생. 왜냐면 nums는 요소의 타입이 int니까.
        // }
        vector<string> str_nums;
        for (auto num : nums){
            str_nums.push_back(to_string(num));
        }

        //2) custom 비교함수 사용해서 정렬.
        sort(str_nums.begin(), str_nums.end(), cmp);

        //3)결과 문자열 생성
        string result;
        for (auto s_num : str_nums){
            result += s_num;
        }

        //4)만약 '0'으로 시작하면 "0" 반환
        return result[0] == '0'? "0" : result;
    }
};