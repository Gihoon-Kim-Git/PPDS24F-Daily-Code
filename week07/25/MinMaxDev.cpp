#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
    public:
    int solution(int K, int M, vector<int> &A) {
        
        int _max = accumulate(A.begin(), A.end(), 0);
        int _min = M;
        int result = _max;

        while (_min <= _max) {
            int mid = (_min + _max) /2;
            int _k = 1; // currrent block
            int sum =0;
            for (int i=0; i<A.size(); ++i) {
                if (sum+A[i] <= mid) {sum+=A[i];}
                else {
                    ++_k;
                    sum = A[i];
                }
            }
            // check
            if (_k<=K) {
                result = mid;
                _max = mid-1;}
            else {_min = mid+1;}            

        }
        return result;
    }
};

int main(void) {

    vector<int> A = {2,1,5,1,2,2,2};
    Solution B;
    cout << B.solution(3,5,A)<< endl;
    return 1;
}