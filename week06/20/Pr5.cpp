#include <unordered_map>
#include <algorithm>
#include <initializer_list>
#include <string>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        std::unordered_map<char,int> m;
        for(char ch : text){
            if(m.find(ch)==m.end()){
                m[ch]=1;
            }else m[ch]++;
        }
        int numb = (m.find('b')!=m.end()) ? m['b'] : 0;
        int numa = (m.find('a')!=m.end()) ? m['a'] : 0;
        int numl = (m.find('l')!=m.end()) ? m['l']/2 : 0;
        int numo = (m.find('o')!=m.end()) ? m['o']/2 : 0;
        int numn = (m.find('n')!=m.end()) ? m['n'] : 0;
        return min({numb,numa,numl,numo,numn});
        //C++에선 #algoritgm -> min/max , initializer_list -> { } 로 min/max 비교가능
    }
};