#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    
    for (int i = 0; i < 32; i++) {
        // Extract the least significant bit of n
        uint32_t bit = n & 1;
        // Shift result to the left and add the extracted bit
        result = (result << 1) | bit;
        // Shift n to the right to process the next bit
        n >>= 1;
    }
    
    return result;
}

int main() {
    uint32_t n = 43261596;  // Example input: 00000010100101000001111010011100
    uint32_t reversed = reverseBits(n);
    printf("Reversed bits: %u\n", reversed);  // Output should be 964176192
    return 0;
}