/*문제
We are playing the Guessing Game. The game will work as follows:

    1. I pick a number between 1 and n.
    2. You guess a number.
    3. If you guess the right number, you win the game.
    4. If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
    5. Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
    6. Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

Constraint: 
    1 <= n <= 200
*/

/*수도코드1 : Recursive
    1. X 숫자가 들어왔을 때의 이기기 위해 필요한 최대 돈 = x +  MAX((LOW, x-1), (x+1, HIGH))
    2. x를 돌면서, "각 X에서의 필요한 최대 돈" 중 MIN 값 찾아 반환.
*/
#include <iostream>
using namespace std;
#define MAX_INT 2147483647

class Solution{
public:
    int getMoneyAmountHelp(int low, int high){
        if (low >= high) return 0;

        int min_cost = MAX_INT;

        for (int x = low ; x <= high ; x++){
            int low_to_x = getMoneyAmountHelp(low, x-1);
            int x_to_high = getMoneyAmountHelp(x+1, high);
            int max_cost = low_to_x > x_to_high ? low_to_x : x_to_high;
            int cost = x + max_cost;
            if (min_cost > cost) min_cost = cost;
        }
        return min_cost;

    }
    int getMoneyAmount(int n){
        return getMoneyAmountHelp(1, n);
    }
};


/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/*수도코드2 : Top down
    1. low, high 각각 축으로 가지는 2D vector인 DPT정의
    2. 2D array의 값을 -1로 초기화
    3. 만약 DPT[low][high] 값이 -1이면 recursive로 직접 구하고
        DPT[low][high] 값이 -1이 아니면 저장된 값 사용.
*/

#include <iostream>
#include <vector>
using namespace std;
#define MAX_INT 2147483647

class Solution{
public:
    int getMoneyAmountHelp(int low, int high, vector<vector<int>> &DPT){
        if (low >= high) return 0;

        if (DPT[low][high] != -1) return DPT[low][high];

        int min_cost = MAX_INT;
        for (int x = low ; x <= high ; x++){
            int low_to_x = getMoneyAmountHelp(low, x-1, DPT);
            int x_to_high = getMoneyAmountHelp(x+1, high, DPT);
            int max_cost = low_to_x > x_to_high ? low_to_x : x_to_high;
            int cost = x + max_cost;
            if (min_cost > cost) min_cost = cost;
        }
        DPT[low][high] = min_cost;
        return DPT[low][high];

    }
    int getMoneyAmount(int n){
        vector<vector<int>> DPT = {}; 
        //vector<vector<int>> DPT(n+1, vector<int>(n+1, -1));  //이렇게 한줄로 초기선언하는 것도 가능.
        for (int i = 0; i < n+1; i++) {
            vector<int> DPT_row(n+1, -1);
            DPT.push_back(DPT_row);
        }

        return getMoneyAmountHelp(1, n, DPT);
    }
};

/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/*수도코드3 : Bottom up
    1. low, high 각각 축으로 가지는 2D vector인 DPT정의
    2. low, high 간의 범위를 2~10까지 조정해가면서 
        해당 범위 내에서의 start, end에 따른 min_cost 값을 DPT에 저장.
    3. return DPT[1][n]
*/
#include <iostream>
#include <vector>
using namespace std;
#define MAX_INT 2147483647

class Solution{
public:
    int getMoneyAmount(int n){
        vector<vector<int>> DPT(n+1, vector<int>(n+1, 0));  //이렇게 한줄로 초기선언하는 것도 가능.

        for (int length = 2; length <= n; length++){
            for (int start = 1; start <= n-length+1; start++){
                int end = start + length -1;
                DPT[start][end] = MAX_INT;
                for (int x = start; x <= end; x++) {
                    int cost;
                    if (x == end) { // x가 범위의 끝이면 오른쪽에 더이상 고려할 숫자 없음. (x==start일 경우는 어차피 자동으로 이 됨.)
                        cost = x + DPT[start][x-1];  // x가 end와 같을 때는 오른쪽 범위가 없으므로
                    } else {
                        int left = DPT[start][x-1];  // 왼쪽 범위의 최대 비용
                        int right = DPT[x+1][end];  // 오른쪽 범위의 최대 비용
                        cost = x + max(left, right);  // x를 선택했을 때의 총 비용
                    }
                    DPT[start][end] = min(DPT[start][end], cost);  // 최소 비용 갱신
                }
            }
        }
        return DPT[1][n];  // 1부터 n까지의 최소 비용 반환
    }
};


/* 추가 설명 참고
코드에서 x == end 조건을 특별히 검사하는 이유는 선택된 숫자 x가 범위의 끝일 때 오른쪽에 더 이상 고려할 숫자가 없기 때문입니다. 이 경우, 추가적인 비용은 왼쪽 범위의 최대 비용과 x 자신의 비용만을 고려하면 됩니다. 오른쪽 범위는 존재하지 않으므로, 그 비용은 0입니다.

그러나 x == start인 경우를 별도로 처리하지 않는 이유는 다음과 같습니다:

비대칭적 조건: 문제의 특성 상, x를 선택할 때의 비용 계산은 x를 기준으로 왼쪽 범위(start부터 x-1)와 오른쪽 범위(x+1부터 end)의 최대 비용을 고려합니다. x가 start와 같을 때는 왼쪽 범위가 없기 때문에, 왼쪽 범위의 최대 비용은 자동으로 0입니다. 이는 코드 로직에서 자연스럽게 처리됩니다. 즉, x-1이 start-1이 되므로, 이 범위는 유효하지 않으며, 이 때의 최대 비용은 0으로 간주됩니다.

코드 단순화: x == start를 명시적으로 처리하는 것은 필요하지 않습니다. 왜냐하면 이 경우의 왼쪽 비용은 자동으로 0이 되기 때문입니다. 이를 명시적으로 코드에 쓰지 않아도 DPT[start][x-1]는 유효 범위를 벗어나는 인덱스 접근이 아닙니다. Python에서는 리스트 접근이 범위를 벗어나면 오류를 발생시키지만, C++에서는 벡터의 특정 인덱스 접근이 범위를 벗어나면 초기화되지 않은 메모리를 읽을 수 있으므로, 초기화된 동적 프로그래밍 테이블을 사용하여 이러한 문제를 방지합니다.

결국, 이 코드는 x의 위치가 start이든 end이든 각 위치에 따른 적절한 조건 처리를 통해 문제 요구사항을 효과적으로 충족합니다. x == start에서는 왼쪽 비용이 자동으로 0이 되고, x == end에서는 오른쪽 비용이 0이 됩니다. 이러한 방식으로 모든 가능한 위치에서 최소 비용을 찾아내는 로직을 구현합니다.*/