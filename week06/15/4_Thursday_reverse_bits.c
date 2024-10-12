#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    unsigned int ans = 0;
    for (int i = 0; i < 32; i++) {
        ans = (ans << 1) + (n & 1);
        n >>= 1;
    }
    return ans;
}