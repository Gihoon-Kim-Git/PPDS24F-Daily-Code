#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t current;
    uint32_t result = 0;
    for (int i=0; i<32; i++) {
        current = (n>>(i)) & 1;
        result += pow(2,(31-i)) * current;
    }
    return result;
} 

int main() {
    uint32_t answer = reverseBits(43261596);
    printf("answer is %u\n", answer);
}