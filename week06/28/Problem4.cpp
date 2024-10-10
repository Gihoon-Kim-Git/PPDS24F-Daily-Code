#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int length = sizeof(n) * 8;
        int toLeft = 0;
        int toRight = length - 1;
        uint32_t result = 0;

        while(toLeft<=length && toRight>=0){
            uint32_t compare = 1 << toLeft;
            uint32_t cur = n<<toLeft++;
            cur >>= toRight--;
            cur &= compare;
            result += cur;
        }
        return result;
    }
};