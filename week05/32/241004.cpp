#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> result(12, 0);
    result[0] = 0;
    result[1] = 1;
    result[2] = 2;
    result[3] = 4;

    for (int i=4; i <= 12; i++) {
        result[i] = result[i-1] + result[i-2] + result[i-3];
    }
    int T;
    cin >> T;

    for (int i=0; i < T; i++) {
        int n;
        cin >> n;
        cout << result[n] << endl;
    }
    return 0;
}