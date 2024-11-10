// 1611. Minimum One Bit Operations to Make Integers Zero
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n==0) return 0;//base case
        int shift=floor(log2(n));
        int x=(1<<(shift+1))-1;
        return x-minimumOneBitOperations(n^(1<<shift));
    }
};