// This function calculates the minimum number of bit operations required to transform
// an integer n into 0. We can perform two operations:
// 1. Flip the rightmost (0th) bit in the binary representation of n.
// 2. Flip the ith bit if the (i-1)th bit is 1 and all lower bits are 0.
// By recursively solving the problem with these constraints, we use bit manipulation
// to efficiently calculate the minimum operations required.
#include <stdio.h>

/* GPT SOLUTION */
// Function to calculate the minimum operations required using Gray code manipulation
int minimumOneBitOperations(int n) {
    int result = 0;
    // While loop that processes bits from the most significant bit down to 0
    while (n > 0) {
        // XOR the result with the current number to accumulate the cost
        result ^= n;
        // Right-shift n to remove the least significant bit (move to the next bit)
        n >>= 1;
    }
    return result;
}

// Example usage
int main() {
    int n1 = 3;
    printf("Minimum operations to transform %d to 0: %d\n", n1, minimumOneBitOperations(n1)); // Output: 2
    
    int n2 = 6;
    printf("Minimum operations to transform %d to 0: %d\n", n2, minimumOneBitOperations(n2)); // Output: 4

    return 0;
}

// 0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week10 (main)
// $ gcc min_onebitop.c -o ob

// 0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week10 (main)
// $ ./ob
// Minimum operations to transform 3 to 0: 2
// Minimum operations to transform 6 to 0: 4