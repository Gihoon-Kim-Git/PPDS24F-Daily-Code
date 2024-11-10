// ## Friday. [Maximum number of balloons](https://leetcode.com/problems/maximum-number-of-balloons/description/)
// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

// Example 1:



// Input: text = "nlaebolko"
// Output: 1
// Example 2:



// Input: text = "loonbalxballpoon"
// Output: 2
// Example 3:

// Input: text = "leetcode"
// Output: 0
 

// Constraints:

// 1 <= text.length <= 104
// text consists of lower case English letters only.



// 각 알파벳 별로 개수 센 다음에, 
// b a ll oo n
// b, a, l/2, o/2, n 중에서 최솟값 반환하면 됨

// string 순회



#include <string>
#include <algorithm>

using namespace std;



class Solution {
public:
    int maxNumberOfBalloons(string text) {

        int text_length = text.length();
        int b_cnt=0, a_cnt=0, l_cnt=0, o_cnt=0, n_cnt=0;

        for (int i=0; i<text_length; i++){

            if (text[i] == 'b') {
                b_cnt++;
            } else if (text[i] == 'a'){
                a_cnt++;
            } else if (text[i] == 'l'){
                l_cnt++;
            } else if (text[i] == 'o'){
                o_cnt++;
            } else if (text[i] == 'n'){
                n_cnt++;
            } 
        }

        int sol = min({b_cnt, a_cnt, l_cnt/2, o_cnt/2, n_cnt});
        
        return sol;
    };
};