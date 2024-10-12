#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    
    // 1. 32번 반복해야 함 (32비트이므로)
    for (int i = 0; i < 32; i++) {
        // 2. n의 마지막 비트를 가져옴 (n & 1)
        // 2.1. result를 왼쪽으로 한 칸 이동시키고 (result << 1)
        // 2.2. n의 마지막 비트(n & 1)를 result에 추가
        result = (result << 1) | (n & 1);
        
        // 3. n을 오른쪽으로 한 칸 이동시켜 다음 비트를 준비함 (n >> 1)
        n >>= 1;
    }
    
    // 4. 모든 비트를 뒤집은 result를 반환함
    return result;
}


int main() {
    // 테스트 케이스 1: 입력값 43261596 (00000010100101000001111010011100)
    uint32_t n1 = 43261596;
    uint32_t result1 = reverseBits(n1);
    printf("Reversed bits of %u: %u\n", n1, result1); // 예상 출력: 964176192

    // 테스트 케이스 2: 입력값 4294967293 (11111111111111111111111111111101)
    uint32_t n2 = 4294967293;
    uint32_t result2 = reverseBits(n2);
    printf("Reversed bits of %u: %u\n", n2, result2); // 예상 출력: 3221225471

    return 0;
}