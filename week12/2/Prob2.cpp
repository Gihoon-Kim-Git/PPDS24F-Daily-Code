#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // 숫자들을 문자열로 변환하여 벡터에 저장
        vector<string> numStrings;
        for(int num : nums){
            numStrings.push_back(to_string(num));
        }

        // 사용자 정의 비교 함수로 정렬
        sort(numStrings.begin(), numStrings.end(), [](const string &a, const string &b){
            return a + b > b + a;
        });

        // 정렬 후 가장 큰 수가 '0'인 경우 (예: [0, 0]인 경우) "0" 반환
        if(numStrings[0] == "0"){
            return "0";
        }

        // 결과 문자열 생성
        string result;
        for(const string &numStr : numStrings){
            result += numStr;
        }

        return result;
    }
};
