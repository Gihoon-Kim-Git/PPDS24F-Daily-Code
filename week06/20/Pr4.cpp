#include <cmath>

class Solution {
public:
    int reverseBits(int n) {
        int  num = 31;
        int long long ans = 0;
        while(n!=0){
            if( n & 1 == 1) ans += std::pow(2,num);
            num--;
            n = n >> 1; 
        }
        return ans;
    }
};