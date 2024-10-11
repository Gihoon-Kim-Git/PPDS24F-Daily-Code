
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        //이 문제는 32비트라고 비트 수가 정해져있음

        uint32_t reversed=0;

        for(int i=0; i<32; i++)
        {
            reversed=reversed<<1;
            reversed=reversed | (n & 1); //끝자리 비트와 1을 비교해서 집어넣는다.
            n=n>>1;
        }

        return reversed;

    }
};

//uint32_t는 부호없는 32비트 정수형을 의미함

//string으로 바꾸는 방법: to_string
//std::to_string(n);

//정수형으로 바꾸는 방법: std::stoul (string to unsigned long)
//std::stoul(a, 10); --> 10진수