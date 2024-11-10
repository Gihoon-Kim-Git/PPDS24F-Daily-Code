#include <iostream>
using namespace std;

class Solution {
public:
    int solution(int K, vector<int> &A) {
        int count = 0, temp = 0;
        for (int i=0; i<A.size(); i++) {
            if (temp+A[i] < K) temp += A[i];
            else {
                count++;
                temp = 0;
            }
        }
        return count;
    }
};

int main() {
    vector<int> A = {1,2,3,4,1,1,3};
    Solution result;
    cout << result.solution(4, A) << endl;

    return 0;
}