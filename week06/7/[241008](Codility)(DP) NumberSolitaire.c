/* 문제
A game for one player is played on a board consisting of N consecutive squares, numbered from 0 to N − 1. There is a number written on each square. A non-empty array A of N integers contains the numbers written on the squares. Moreover, some squares can be marked during the game.

At the beginning of the game, there is a pebble on square number 0 and this is the only square on the board which is marked. The goal of the game is to move the pebble to square number N − 1.

During each turn we throw a six-sided die, with numbers from 1 to 6 on its faces, and consider the number K, which shows on the upper face after the die comes to rest. Then we move the pebble standing on square number I to square number I + K, providing that square number I + K exists. If square number I + K does not exist, we throw the die again until we obtain a valid move. Finally, we mark square number I + K.

After the game finishes (when the pebble is standing on square number N − 1), we calculate the result. The result of the game is the sum of the numbers written on all marked squares.

For example, given the following array:

    A[0] = 1
    A[1] = -2
    A[2] = 0
    A[3] = 9
    A[4] = -1
    A[5] = -2
one possible game could be as follows:

the pebble is on square number 0, which is marked;
we throw 3; the pebble moves from square number 0 to square number 3; we mark square number 3;
we throw 5; the pebble does not move, since there is no square number 8 on the board;
we throw 2; the pebble moves to square number 5; we mark this square and the game ends.
The marked squares are 0, 3 and 5, so the result of the game is 1 + 9 + (−2) = 8. This is the maximal possible result that can be achieved on this board.

Write a function:

int solution(int A[], int N);


that, given a non-empty array A of N integers, returns the maximal result that can be achieved on the board represented by array A.

For example, given the array

    A[0] = 1
    A[1] = -2
    A[2] = 0
    A[3] = 9
    A[4] = -1
    A[5] = -2
the function should return 8, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−10,000..10,000].*/

/*문제풀이
    1. 점화식 구하기
        N = 0 -> A[0]
        N = 1 -> A[1] + A[0]
        N = 2 -> A[2] + A[0]
        N = 3 -> A[3] + A[0]
        N = 4 -> A[4] + A[3] + A[0]
        N = 5 -> A[5] + A[3] + A[0]
        R[N] = A[N] + max(R[N-1], R[N-2], R[N-3], R[N-4], R[N-5], R[N-6])  # 주사위 6칸
    2. 점화식 조건   R[n] = A[n] + max(R[n-1], R[n-2], R[n-3], R[n-4], R[n-5], R[n-6])
        if n < 0 or n > (N-1) : R[n] = 없음. (-20000으로 할까도 생각했지만 덮어쓰는 등의 문제 생길듯 n이 음수일때)
        else :
            if n == 0 : R[n] = A[n]
            elif n == 1 : R[n] = A[n] + A[0]
            elif n == 2 : R[n] = A[n] + max(R[n-1], R[n-2])
            elif n == 3 : R[n] = A[n] = max(R[n-1], R[n-2], R[n-3])        
            elif n == 3 : R[n] = A[n] = max(R[n-1], R[n-2], R[n-3])        
            elif n == 4 : R[n] = A[n] = max(R[n-1], R[n-2], R[n-3], R[n-4])        
            elif n == 5 : R[n] = A[n] = max(R[n-1], R[n-2], R[n-3], R[n-4], R[n-5])        
            else (n>=6) : R[n] = A[n] = max(R[n-1], R[n-2], R[n-3], R[n-4], R[n-5], R[n-6])      
    3. R array를 만들 때 malloc.또는 calloc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  //또는 #define MY_INT_MIN (-2147483647 - 1)


int solution(int A[], int N){
    int* R = (int*)calloc(N, sizeof(int)); // N개만큼 0으로 초기화 )

    for (int i = 0 ; i < N; i++){
        if (i == 0) R[i] = A[i];
        else if (i == 1) R[i] = A[i] + A[0];
        else if (i >= 2 && i <= 5){
            int max_R = INT_MIN; //-20000으로 했을 때는 A가 전부 -20000처럼 매우 작은 수로 이루어졌을 때 wrong_answer
            for (int j = 1; j <= i; j++){
                if (max_R < R[i-j]) max_R = R[i-j];
            }
            R[i] = A[i] + max_R;
        }
        else { // i >= 6
            int max_R = INT_MIN;
            for (int j = 1; j <= 6; j++){
                if (max_R < R[i-j]) max_R = R[i-j];
            }
            R[i] = A[i] + max_R;
            }
    }

    int answer = R[N-1];
    free(R);
    return answer;
}  

int main(){
    int A[] = [0, -4, -5, -2, -7, -9, -3, -10];
    int N = 8;
    int answer = solution(A,N );
    printf("%d\n", answer);

    return 0;
}