class Solution {
public:
    int minimumOneBitOperations(int n) {
        //가장 왼쪽 비트부터 탐색해서 1이 나오면 -> 그 비트의 오른쪽 비트 확인 & 더 오른쪽 비트들도 확인
        //오른쪽 비트가 1이면 바로 0으로 바꿈 1
        //오른쪽 비트가 0이면 오른쪽 비트 1로 바꾸고, 0으로 바꿈 2회

        int operations = 0;

            // 가장 왼쪽 비트를 탐색하기 위해 비트 위치 확인
            for (int i = 31; i >= 0; --i) {
                if ((n & (1 << i)) != 0) {  // i번째 비트가 1인지 확인
                    if (i > 0 && (n & (1 << (i - 1))) != 0) {
                        // 오른쪽 비트가 1이면 해당 비트를 0으로 바꿈 (연산 1회)
                        n &= ~(1 << i);  // i번째 비트를 0으로 설정
                        operations += 1;
                        cout<<n<<endl;
                    } else {
                        // 오른쪽 비트가 0이면 오른쪽 비트를 1로 바꾸고 현재 비트 0으로 바꿈 (연산 2회)
                        if (i > 0) {
                            n |= (1 << (i - 1));  // 오른쪽 비트를 1로 설정
                            operations += 2;
                        }
                        else{
                            operations++;
                        }
                        n &= ~(1 << i);  // i번째 비트를 0으로 설정
                        cout<<n<<endl;
                    }
                }
            }

        return operations;
    }
};