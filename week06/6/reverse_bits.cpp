/*

Reverse bits of a given 32 bits unsigned integer.

Note:

- Note that in some languages, such as Java, there is no unsigned integer type.
In this case, both input and output will be given as a signed integer type. They
should not affect your implementation, as the integer's internal binary
representation is the same, whether it is signed or unsigned.

- In Java, the compiler represents the signed integers using 2's complement
notation. Therefore, in Example 2 above, the input represents the signed integer
-3 and the output represents the signed integer -1073741825.

Example 1:

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents
the unsigned integer 43261596, so return 964176192 which its binary
representation is 00111001011110000010100101000000.

Example 2:

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents
the unsigned integer 4294967293, so return 3221225471 which its binary
representation is 10111111111111111111111111111111.

*/
// #include <algorithm>
#include <cassert>
#include <cstdint>
// #include <sstream>
// #include <string>

using namespace std;

// Sanity check
// string ToBinary(uint32_t n) {
//   ostringstream s;
//   for (int i = 0; i < 32; ++i) {
//     int first = n & 1;
//     s << to_string(first);
//     n >>= 1;
//   }
//   string res = s.str();
//   reverse(res.begin(), res.end());
//   return res;
// }

uint32_t ReverseBits(uint32_t n) {
  uint32_t r = 0;
  for (int i = 0; i < 31; ++i) {
    int first = n & 1;
    r += first;
    r <<= 1;
    n >>= 1;
  }
  r += n & 1;
  return r;
}

int main() {
  uint32_t n1 = 43261596;
  uint32_t a1 = 964176192;
  assert(ReverseBits(n1) == a1);

  uint32_t n2 = 4294967293;
  uint32_t a2 = 3221225471;
  assert(ReverseBits(n2) == a2);
}