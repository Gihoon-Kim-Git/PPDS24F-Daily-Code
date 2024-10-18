#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    int MaxProduct(vector<int> &A) {
        if (A.size()==3) {return A[0]*A[1]*A[2];}
        sort(A.begin(), A.end());
        int cand1 = A[A.size()-1]*A[A.size()-2]*A[A.size()-3];
        int cand2 = INT_MIN;
        if (A[0]<0 && A[1]<0) {cand2 = A[0]*A[1]*A[A.size()-1];}

        if (cand1 >= cand2) {return cand1;}
        else {return cand2;}
    }
};

int main(void) {
    vector<int> A = {-3, 1, 2, -2, 5, 6};
    Solution B;
    cout << B.MaxProduct(A) << endl;
  

    return 1;
}