#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i=1; i<=32; i++) {
        result += (n % 2) * pow(2, 32-i);
        n /= 2;
    }
    return result;
}

int main() {
    uint32_t n1 = 0b00000010100101000001111010011100;
    uint32_t n2 = 0b11111111111111111111111111111101;
    
    printf("%u\n", reverseBits(n1));
    printf("%u\n", reverseBits(n2));

    return 0;
}