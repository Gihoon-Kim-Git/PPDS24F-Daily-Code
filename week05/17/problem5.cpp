// 정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

// 1+1+1+1
// 1+1+2
// 1+2+1
// 2+1+1
// 2+2
// 1+3
// 3+1
// 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

// 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.
// 각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.

// recursive로 풀어보기


#include <iostream>
#include <vector>


int countSum(int n){
    if (n == 1){
        return 1;
    } else if (n == 2){
        return 2;
    } else if (n == 3){
        return 4;
    }
    return countSum(n-1) + countSum(n-2) + countSum(n-3);
}


int main(){

    int T, n;

    std::cin >> T;

    for (int i = 0; i < T; ++i){
        std::cin >> n;
        std::cout << countSum(n) << std::endl;
    }

    return 0;
}