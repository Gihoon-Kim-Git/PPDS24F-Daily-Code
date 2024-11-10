#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    
    // Process all 32 bits one by one
    for (int i = 0; i < 32; i++) {
        result <<= 1;        // Shift result left to make space for the next bit
        result |= (n & 1);   // Add the least significant bit of n to result
        n >>= 1;             // Shift n right to process the next bit
    }
    
    return result;
}
