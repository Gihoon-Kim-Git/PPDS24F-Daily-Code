// Sort Characters By Frequency
// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.
// 대소문자 관계없이 빈도수로 string 재정렬
// ex. Input: s = "tree"
//     Output: "eert"


class Solution {
public:
    string frequencySort(string s) {
        // map로 count (python의 dictionary와 유사) 
        unordered_map<char, int> freq;
        for(char c:s){
            freq[c]++;
        }

        // 자동 내림차순 정렬되는 priority queue 성질 활용
        priority_queue<pair<int, char>> Maxheap;
        for(const auto& entry:freq){
            Maxheap.push({entry.second, entry.first});
        }

        string ans;
        while(!Maxheap.empty()){
            auto [val,key] = Maxheap.top();
            Maxheap.pop();
            ans.append(val,key);
        }

        return ans;
    }
};