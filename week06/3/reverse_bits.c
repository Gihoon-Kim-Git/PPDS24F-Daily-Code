/*
 * Reverse bits of a given 32-bit unsigned integer.
 *
 * Note:
 * - In some languages, such as Java, there is no unsigned integer type.
 *   In this case, both input and output will be given as a signed integer type.
 *   This should not affect your implementation, as the integer's internal binary 
 *   representation is the same whether it is signed or unsigned.
 *
 * - In Java, the compiler represents signed integers using 2's complement notation.
 *   Therefore, in Example 2, the input represents the signed integer -3, and 
 *   the output represents the signed integer -1073741825.
 *
 * Example 1:
 * Input: n = 00000010100101000001111010011100
 * Output:    964176192 (00111001011110000010100101000000)
 * Explanation: The input binary string 00000010100101000001111010011100 represents 
 *              the unsigned integer 43261596, so return 964176192, which is the 
 *              binary representation 00111001011110000010100101000000.
 *
 * Example 2:
 * Input: n = 11111111111111111111111111111101
 * Output:   3221225471 (10111111111111111111111111111111)
 * Explanation: The input binary string 11111111111111111111111111111101 represents 
 *              the unsigned integer 4294967293, so return 3221225471, which is the 
 *              binary representation 10111111111111111111111111111111.
 *
 * Constraints:
 * - The input must be a 32-bit unsigned integer.
 *
 * Follow-up:
 * - If this function is called many times, how would you optimize it?
 */

#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0; // store reversed bits
    int i;

    // iteration over all 32 bits of the input number
    for (i=0; i<32; i++) {
        // shift result to left: make space for next bit
        ans <<= 1;

        // add least significant bit of n to answer
        ans |= (n&1);

        // shift n to the right to process next bit
        n >>= 1;
    }

    // after processing all 32 bits, ans contains reversed bits
    return ans;
}

// Helper function to print the binary representation of a 32-bit unsigned integer
void printBinary(uint32_t n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0) printf(" "); // for readability
    }
    printf("\n");
}

// Test cases for the reverseBits function
void test_reverseBits() {
    // Test case 1: Input is 00000010100101000001111010011100 (binary), which is 43261596 in decimal
    uint32_t input1 = 43261596;
    uint32_t output1 = reverseBits(input1);
    printf("Input: %u, Output: %u\n", input1, output1);
    printf("Input (binary): ");
    printBinary(input1);
    printf("Output (binary): ");
    printBinary(output1);
    printf("Expected Output: 00111001011110000010100101000000 (964176192)\n\n");

    // Test case 2: Input is 11111111111111111111111111111101 (binary), which is 4294967293 in decimal
    uint32_t input2 = 4294967293;
    uint32_t output2 = reverseBits(input2);
    printf("Input: %u, Output: %u\n", input2, output2);
    printf("Input (binary): ");
    printBinary(input2);
    printf("Output (binary): ");
    printBinary(output2);
    printf("Expected Output: 10111111111111111111111111111111 (3221225471)\n\n");

    // Test case 3: Input is all zeros (0)
    uint32_t input3 = 0;
    uint32_t output3 = reverseBits(input3);
    printf("Input: %u, Output: %u\n", input3, output3);
    printf("Input (binary): ");
    printBinary(input3);
    printf("Output (binary): ");
    printBinary(output3);
    printf("Expected Output: 00000000000000000000000000000000 (0)\n\n");

    // Test case 4: Input is all ones (4294967295)
    uint32_t input4 = 4294967295;
    uint32_t output4 = reverseBits(input4);
    printf("Input: %u, Output: %u\n", input4, output4);
    printf("Input (binary): ");
    printBinary(input4);
    printf("Output (binary): ");
    printBinary(output4);
    printf("Expected Output: 11111111111111111111111111111111 (4294967295)\n\n");
}

int main() {
    // Run test cases
    test_reverseBits();
    return 0;
}