/*Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.*/

/*Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.*/

/*수도코드
    1. 단어를 순회하면서 map에 저장한다. key : 알파벳, value: 횟수
    2. map을 value 기준으로 내림차순 정렬한다.
    3. map을 순회하면서 value*key를 answer string에 더해준다.
*/

#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    //value 기준으로 정렬하기 위한 비교함수 정의 (객체 생성없이도 사용하기 위해서 static으로 선언해줌.)
    static bool cmp(const pair<char, int>& a, const pair<char, int>& b){
        return a.second > b.second;  //이건 내림차순 정렬. a.second < b.second 했으면 오름차순 정렬임.
    }

    string frequencySort(string s) {
        map<char, int> char_count;

        for (auto c : s){
            char_count[c]++;
        }

        //map을 value 기준으로 정렬하기 
            //1) map을 vector로 이동
            //2) vector를 second 기준으로 정렬
        vector<pair<char, int>> all_counts(char_count.begin(), char_count.end());
        sort(all_counts.begin(), all_counts.end(), cmp);

        //all_counts 벡터를 순회하면서 답 만들기
        string answer;
        for (auto char_int_pair : all_counts){
            //append(size_t n, char c)
            answer.append( char_int_pair.second, char_int_pair.first); //append를 써야 한꺼번에 여러 글자를 더할 수 있음. (+= 사용하려면 반복문 써야함)
        }

        return answer;

    }
};