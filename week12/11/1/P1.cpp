#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count character frequencies using a fixed-size array
        int freq[128] = {0}; // ASCII range
        for (char ch : s) {
            freq[ch]++;
        }

        // Step 2: Sort the string based on frequencies
        string result;
        int maxFreq = 1;
        while (maxFreq != 0) {
            char maxChar = 0;
            maxFreq = 0;

            // 가장 많이 나온 char 찾기
            for (int i = 0; i < 128; ++i) {
                if (freq[i] > maxFreq) {
                    maxFreq = freq[i];
                    maxChar = i;
                }
            }

            // 가장 많이 나온 char를 maxFreq만큼 추가
            result.append(maxFreq, maxChar);

            // 이미 한건 0으로 변경
            freq[maxChar] = 0;
        }

        return result;
    }
};


int main(void){
    string s = "aabedddd";
    Solution c;
    cout << c.frequencySort(s) << endl;
    return 0;
}