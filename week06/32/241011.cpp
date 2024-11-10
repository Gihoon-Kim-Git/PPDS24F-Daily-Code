class Solution {
public:
    int maxNumberOfBalloons(string text) {
        std::unordered_map<char, int> m;
        for (char n : {'b', 'a', 'l', 'o', 'n'}) {
            m[n] = 0;
        }

        for (int i=0; i < text.size(); ++i) {
            m[text[i]]++;
        }
        int mini = 10000;
        for (auto pair : m) {
            if (pair.first == 'l' || pair.first == 'o') {
                mini = min(mini, pair.second / 2);
            } else if (pair.first == 'b' || pair.first == 'a' || pair.first == 'n') {
                mini = min(mini, pair.second);
            } else {}
        }

        for (auto pair : m) {
            cout << pair.first << " " << pair.second << endl;
        }

        return mini;
    }
};