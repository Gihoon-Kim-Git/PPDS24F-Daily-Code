#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int count = 0;
        while(true){

            for(char c : "balloon"){
                auto pos = find(text.begin(), text.end(), c);
                if(pos == text.end()){
                    return count;
                }
                *pos = '\0';
            }
            
            count++;
        }
    }
};