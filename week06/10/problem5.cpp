#include <iostream>
#include <cstring>
#include <vector>


class Solution {
public:
    int maxNumberOfBalloons(std::string text) {
        
        std::string bal = "balloon";
        std::string copy = text;
        
        std::vector<int> copy_vec(26, 0);
        std::vector<int> bal_vec(26, 0) ;

        for (char c: copy) {
            copy_vec[c - 'a'] += 1;
        }
        for (char b: bal) {
            bal_vec[b - 'a'] += 1; 
        }
 
        int cnt_char = 10001;
        int cnt_word = 0; 
        int cnt_temp = 0;
        int i = 0;
        while (i < 26) {
            if (bal_vec[i] != 0 && bal_vec[i] <= copy_vec[i]){
                cnt_temp = copy_vec[i]/bal_vec[i];
                if (cnt_char > cnt_temp){
                    cnt_char = cnt_temp; 
                }
                if (copy_vec[i]%bal_vec[i]==0){ 
                    cnt_word += bal_vec[i]; 
                } else {
                    cnt_word +=  ((copy_vec[i] - (copy_vec[i]/bal_vec[i])) / bal_vec[i]);

                }

            }
            i++;
        }
        if (cnt_char == 10001) return 0;
        else if (cnt_word < bal.length()) return 0;
        else return cnt_char;
    }
};