class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        for (size_t i=0; i<32; i++) {
            if (n & 1) {
                // n 의 마지막 bit 가 1 이면
                reversed += 1;
            } else {
                // do nothing
            }
            n >>= 1;
            if (i < 31) {
                // reversed 의 left shift 는 마지막 iteration 에서는 하면 안됨
                reversed <<= 1;
            }
        }
        return reversed;
    }
};
