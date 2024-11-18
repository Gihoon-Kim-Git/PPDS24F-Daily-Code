#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool compare(pair<char, int> &a, pair<char, int> &b) {
    return a.second > b.second;
}

class Solution {
public:
    string frequencySort(string s) {
        string answer;
        unordered_map<char, int> dict;
        for (auto i: s) dict[i] += 1;
        vector<pair<char, int>> vec(dict.begin(), dict.end());
        sort(vec.begin(), vec.end(), compare);
        for (auto j: vec) answer.append(j.second, j.first);
        return answer;
    }   
};

int main() {
    Solution result;
    cout << result.frequencySort("tree") << endl;
    cout << result.frequencySort("cccaaa") << endl;
    cout << result.frequencySort("Aabb") << endl;

    return 0;
}