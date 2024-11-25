#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // 숫자를 문자열로 변환
        vector<string> numStrs;
        for (int num : nums) {
            numStrs.push_back(to_string(num));
        }

        // 정렬 기준 설정: xy와 yx를 비교
        sort(numStrs.begin(), numStrs.end(), [](const string& x, const string& y) {
            return x + y > y + x;
        });

        // 결과 문자열 생성
        string result;
        for (const string& str : numStrs) {
            result += str;
        }

        // 숫자가 모두 0인 경우 처리
        if (result[0] == '0') {
            return "0";
        }

        return result;
    }
};


//메모리 오버플로우 문제가 발생함
// class Solution {
// public:
//     string largestNumber(vector<int>& nums) {
//         vector<int> array(101, 0);

//         for(auto i=0; i<nums.size(); i++){
//             array[nums[i]]++;
//         }
//         string output;

//         //아스키 48-57

//         //9->99~90->89->8->88~80->79~78->7->77~70 ... 

//         for(auto j=9; j>=1; j--){
//             int num=j*10+9;
//             while(num%10>j){
//                 for(auto k=0; k<array[num]; k++){
//                     output+=char(num/10+48);
//                     output+=char(num%10+48);
//                 }
//                 num--;
//             }
            
//             for(auto k=0; k<array[j]; k++){
//                 output+=char(j+48);
//             }
            
//             while(num%10>=0){
//                 for(auto k=0; k<array[num]; k++){
//                     output+=char(num/10+48);
//                     output+=char(num%10+48);
//                 }
//                 if(num%10==0){
//                     break;
//                 }
//                 num--;
//             }
//         }
        
//         return output;
//     }
// };