/*문제
Reverse bits of a given 32 bits unsigned integer.
*/

/*constraint
input must be a binary string of length 32*/

/*문제풀이2 : bit manipulation
    1. binary string을 31칸 왼쪽으로 밀어주면 됨.
*/



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> //unit32_t 사용을 위해서 가져옴.
#include <math.h> //지수승 연산 : pow(밑, 지수)를 위해 가져옴

uint32_t reverseBits(uint32_t n){
    int n_bit[32]; 
    for (int i = 0; i < 32; i++) n_bit[i] = 0;
    int j = 31;
    while (n>=1){
        //int k = n/2   로 하면 runtime error 발생. 왜냐면 그냥 int는 부호있는 정수이기 때문에.
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

int main(){
    int n1 = reverseBits(43261596); //964176192
    printf("%d\n", n1);
    
    int n2 = reverseBits(4294967293); //-1073741825
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