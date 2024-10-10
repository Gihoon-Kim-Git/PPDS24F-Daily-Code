#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string &S) {
    vector<char> left = {'(', '[', '{'};
    map<char, char> pair = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    vector<char> foundLeft;
    for(char s : S){
        if(find(left.begin(), left.end(), s) != left.end()){
            foundLeft.push_back(s);
        }
        else{
            int break_flag = 0;
            for(auto p : pair){
                if(p.second == s && p.first == foundLeft.back()){
                    foundLeft.pop_back();
                    break_flag = 1;
                    break;
                }
            }
            if(break_flag == 0){
                return 0;   
            }
        }  
    }
    if(foundLeft.empty()){
        return 1;
    }
    return 0;
}
