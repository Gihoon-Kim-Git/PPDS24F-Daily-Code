/*문제
Reverse bits of a given 32 bits unsigned integer.
*/

/*constraint
input must be a binary string of length 32*/

/*문제풀이 : C랑 똑같이 풀면 됨*/


#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int n_bit[32];
        for (int i = 0; i < 32; i++) n_bit[i] = 0;
        int j = 31;
        while (n>=1){
            uint32_t k = n/2;
            int b = n - k * 2;
            n = k;
            n_bit[j] = b;
            j--;
        }

        uint32_t n_rev = 0;
        for (int i = 0; i < 32; i++){
            n_rev += (n_bit[31-i]) * pow(2,31-i); }
        return n_rev;
    }
};


int main(){
    Solution s1;
    int n1 = s1.reverseBits(43261596); //964176192
    printf("%d\n", n1);
    
    int n2 = s1.reverseBits(4294967293); //-1073741825
    printf("%d\n", n2);
    
    return 0;
}

//다른 솔루션 : bit manipulation
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans |= (n & 1); //ans |= ...: 이 연산은 ans의 현재 값에 (n & 1)의 결과를 비트 OR 연산(적어도 하나가 1이면 결과도 1)으로 결합합니다. 이는 ans의 마지막 비트에 n의 최하위 비트를 추가하는 것을 의미합니다.
            n >>= 1;
        }
        return ans;
    }

/*분할 정복 접근 방식:
분할(Divide): 32비트를 두 개의 16비트 부분으로 나눕니다. 이 과정을 계속 반복하여 각 부분을 8비트, 4비트, 2비트, 최종적으로는 1비트까지 나눕니다.

정복(Conquer): 가장 작은 단위(1비트)에 도달하면, 뒤집기 작업을 수행할 필요가 없습니다. 그러나 2비트 이상의 그룹에서는 각 그룹 내의 비트 순서를 뒤집습니다.

결합(Combine): 뒤집힌 비트 그룹들을 반대 순서로 다시 합쳐서 전체 비트 순서를 뒤집습니다. 예를 들어, 두 개의 16비트 그룹 A와 B가 있다면, B를 먼저 위치시키고 그 다음에 A를 위치시킵니다.
*/
//분할정복 접근 방식
uint32_t reverseBits(uint32_t n) {
    n = (n >> 16) | (n << 16); // 상위 16비트와 하위 16비트를 교환
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8); // 각 16비트 내에서 상위 8비트와 하위 8비트 교환
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4); // 각 8비트 내에서 4비트씩 교환
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2); // 각 4비트 내에서 2비트씩 교환
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1); // 각 2비트 내에서 1비트씩 교환
    return n;
}