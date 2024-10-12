#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> cand = {{'b',0}, {'a',0}, {'l',0}, {'o',0}, {'n',0}};
        
        for (char each : text) {
            if (each == 'b') {cand['b']++;}
            else if (each == 'a') {cand['a']++;}
            else if (each == 'l') {cand['l']++;}
            else if (each == 'o') {cand['o']++;}
            else if (each == 'n') {cand['n']++;}
        }
        int count = 0;
        while (cand['b']>=1 && cand['a']>=1 && cand['l']>=2 && cand['o']>=1 && cand['n']>=1) {
            count++;

            cand['b']--;
            cand['a']--;
            cand['l'] = cand['l'] - 2;
            cand['o']--;
            cand['n']--;
        } 
        return count;
    }
    
};

int main(void) {
    Solution a;
    int count = a.maxNumberOfBalloons("loonbalxballpoon");
    cout << count << endl;
    return 1;
}