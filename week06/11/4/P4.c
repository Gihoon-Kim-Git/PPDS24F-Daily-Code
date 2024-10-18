#include <stdio.h>
#include <string.h>
#include <stdlib.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for(int i = 0; i < 32; i++){
        if((n >> i) & 1){
            result = result * 2 + 1;
        }
        else{
            result = result * 2;
        }
    }
    return result;
}


int main(void){
    const char *binary_string = "11111111111111111111111111111101";
    unsigned int n = strtoul(binary_string, NULL, 2);

    printf("Input binary string: %s\n", binary_string);
    printf("Input integer: %u\n", n);
    printf("Result: %u\n", reverseBits(n)); 
    return 0;
}