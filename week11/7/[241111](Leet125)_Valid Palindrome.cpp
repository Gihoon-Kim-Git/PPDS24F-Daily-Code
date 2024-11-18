// recursive하게 구현
// 중간에서부터 끝으로 가면서 확인하는 방법

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// two pointer 활용 : 통과
class Solution{
public:
    bool isPalindrome(string s){
        //검사용을 위해 s 정제.
        string text4check = "";
        for (auto c : s){
            if (isalnum(c)){
                if (isupper(c)) text4check += tolower(c);
                else text4check += c;
            }
        }

        if (text4check.size() <= 1) return true;

        //앞, 뒤 각각으로 움직일 pointer 초기화 (짝, 홀수 따라 다름)
        if (text4check.size() %2 == 1){
            int i = text4check.size()/2;
            int j = text4check.size()/2;

            while (i >= 0 && j <= text4check.size()-1){
                if (text4check[i] == text4check[j]){
                    i--;
                    j++;
                }
                else return false;
            }
            return true;
        }
            
        else {
            int i = text4check.size()/2-1;
            int j = text4check.size()/2;

            while (i >= 0 && j <= text4check.size()-1){
                if (text4check[i] == text4check[j]){
                    i--;
                    j++;
                }
                else return false;
            }
            return true;
        }
    }
};






// recursive 구현 : memory exceeded : 480/486
class Solution {
public:
    bool isPalindrome_util(string s, int start, int end){
        if (start >= end) return true;
        if (s[start] != s[end]) return false;
        return isPalindrome_util(s, start+1, end-1);
    }

    bool isPalindrome(string s) {
        //검사용을 위해 s 정제.
        string text4check = "";
        for (auto c : s){
            if (isalnum(c)){
                if (isupper(c)) text4check += tolower(c);
                else text4check += c;
            }
        }

        //text4check길이 체크
        if (text4check.size() <= 1) return true;

        return isPalindrome_util(text4check, 0 , text4check.size()-1);
    }
};


