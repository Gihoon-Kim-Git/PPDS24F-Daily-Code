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

#include <stdio.h>
#define MAX_INT 2147483647 // 2**13 -1 

int getMoneyAmountHelp(int low, int high){ 
    if (low >= high){
        return 0;
    }
    int min_amount = MAX_INT; //매우 큰 값으로 초기화
    for (int x = low; x <= high; x++){
        int low_to_x = getMoneyAmountHelp(low, x-1);
        int x_to_high = getMoneyAmountHelp(x+1, high); 
        int max_cost = low_to_x > x_to_high ? low_to_x : x_to_high;
        int cost = x + max_cost;
        if (min_amount > cost) min_amount = cost;
    }
    return min_amount;
}

int getMoneyAmount(int n){
    return getMoneyAmountHelp(1,n);
}


/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/*수도코드2 : Top down
    1. low, high 각각 축으로 가지는 2D array인 DPT정의
    2. 2D array의 값을 -1로 초기화
    3. 만약 DPT[low][high] 값이 -1이면 recursive로 직접 구하고
        DPT[low][high] 값이 -1이 아니면 저장된 값 사용.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_INT 2147483647 // 2**13 -1 

int getMoneyAmountHelp(int low, int high, int** DPT){
    // 값이 없는 경우 계산1
    if (low >= high) {
        //DPT[low][high] = 0;// index error
        return 0;
    }

    //값이 있는 경우
    if (DPT[low][high] != -1) return DPT[low][high];

    // 값이 없는 경우 계산2
    int min_amount = MAX_INT;
    for (int x = low; x <= high; x++){
        int low_to_x = getMoneyAmountHelp(low, x-1, DPT);
        int x_to_high = getMoneyAmountHelp(x+1, high, DPT); 
        int max_cost = low_to_x > x_to_high ? low_to_x : x_to_high;
        int cost = x + max_cost;
        if (min_amount > cost) min_amount = cost;
        DPT[low][high] = min_amount;
    }
    
    return DPT[low][high];

}

int getMoneyAmount(int n){
    //DP 테이블 초기화
    int** DPT = (int**)malloc(sizeof(int*) * (n+1));

    for (int i = 0; i < n+1; i++){
        int* DPT_row = (int*)malloc(sizeof(int) * (n+1));
        for (int j = 0 ; j < n+1; j++){
            DPT_row[j] = -1; // 값 초기화
        }
        DPT[i] = DPT_row;
    }

    //Top down DP
    int answer = getMoneyAmountHelp(1,n, DPT);

    for (int i = 0 ; i < n+1 ; i++){
        free(DPT[i]);
    }
    free(DPT);
    
    return answer;
}