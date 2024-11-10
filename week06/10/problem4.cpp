#include <stdint.h>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1; // bitwise left shfit ( 0010 -> 0100)
            ans |= (n & 1); 
            n >>= 1;
        }
        return ans;
    }
};