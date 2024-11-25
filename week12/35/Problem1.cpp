/*
451. Sort Characters By Frequency
Medium
Topics:
Hash Table
String
Sorting
Heap (Priority Queue) -> priority queue 사용하는방법
Bucket Sort
Counting

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.



Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        auto cmp = [](const pair<char, int> &a, const pair<char, int> &b)
        {
            return a.second < b.second;
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);

        unordered_map<char, int> hm;

        for (char c : s)
        {
            hm[c]++;
        }

        for (const auto &entry : hm)
        {
            pq.push(make_pair(entry.first, entry.second));
        }

        string result = "";
        while (!pq.empty())
        {
            pair<char, int> p = pq.top();
            pq.pop();
            result.append(p.second, p.first);
        }

        return result;
    }
};
