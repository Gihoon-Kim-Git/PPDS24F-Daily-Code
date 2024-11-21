#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second; // Higher frequency first
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);

        unordered_map<char, int> hm;

        for (char c : s) {
            hm[c]++;
        }

        for (const auto& entry : hm) {
            pq.push(make_pair(entry.first, entry.second));
        }

        string result = "";
        while (!pq.empty()) {
            pair<char, int> p = pq.top();
            pq.pop();
            result.append(p.second, p.first);
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "tree";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << solution.frequencySort(s1) << endl;

    // Test case 2
    string s2 = "cccaaa";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << solution.frequencySort(s2) << endl;

    // Test case 3
    string s3 = "Aabb";
    cout << "Input: " << s3 << endl;
    cout << "Output: " << solution.frequencySort(s3) << endl;

    return 0;
}
