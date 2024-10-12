#include <iostream>
using namespace std;

class Solution {
public:
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
};

int main() {
    Solution solution;
    uint32_t n = 43261596;  // Example input: 00000010100101000001111010011100
    uint32_t reversed = solution.reverseBits(n);
    cout << "Reversed bits: " << reversed << endl;  // Output should be 964176192
    return 0;
}
