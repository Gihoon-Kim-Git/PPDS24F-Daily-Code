#include <iostream>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0, result = INT_MAX;
        for (int i=0; i<text.size(); i++) {
            if (text[i] == 'b') b++;
            if (text[i] == 'a') a++;
            if (text[i] == 'l') l++;
            if (text[i] == 'o') o++;
            if (text[i] == 'n') n++;
        }
        if (b < result) result = b;
        if (a < result) result = a;
        if (l/2 < result) result = l/2;
        if (o/2 < result) result = o/2;
        if (n < result) result = n;
        return result;
    }
};

int main() {
    string t1 = "nlaebolko";
    string t2 = "loonbalxballpoon";

    Solution result;
    cout << result.maxNumberOfBalloons(t1) << endl;
    cout << result.maxNumberOfBalloons(t2) << endl;

    return 0;
}