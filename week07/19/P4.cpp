#include <iostream>
using namespace std;

class Solution {
public:
    bool partition(int K, int mid, vector<int> A) {
        int temp = 0;
        int count = 1;
        for (int i=0; i<A.size(); i++) {
            if (temp+A[i] <= mid) temp += A[i];
            else {
                count++;
                temp = A[i];
            }
        }
        if (count > K) return false;
        return true;
    }

    int solution(int K, int M, vector<int> A) {
        int upper = 0;
        for (int i=0; i<A.size(); i++) upper += A[i];
        int lower = M;
        int result = upper;
        while (lower <= upper) {
            int mid = (upper + lower) / 2;
            if (partition(K, mid, A)) {
                result = mid;
                upper = mid - 1;
            } else lower = mid + 1;
        }
        return result;
    }
};

int main() {
    vector<int> A = {2, 1, 5, 1, 2, 2, 2};
    vector<int> B = {5, 3};
    vector<int> C = {3, 4, 5, 6, 7, 8};
    
    Solution result;
    cout << result.solution(3, 5, A) << endl;
    cout << result.solution(1, 10, B) << endl;
    cout << result.solution(4, 10, C) << endl;

    return 0;
}