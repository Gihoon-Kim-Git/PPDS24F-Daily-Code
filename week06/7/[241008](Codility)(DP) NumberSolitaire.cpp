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

int solution(vector<int> &A)

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
    >> 이 수식 제한되는 이유 : max(a,b)만 문법상 가능함. 따라서 max_element(container) 문법 사용해서 재풀이.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A){
    int aLen = A.size();
    vector<int> R;

    for (int i = 0; i < aLen; i++){
        if (i == 0) R.push_back(A[0]);
        else if (i == 1) R.push_back(A[i] + A[0]);
        else if (i >= 2 && i <= 5){ 
            int maxR = *max_element(R.begin(),R.end());
            R.push_back(A[i] + maxR);
        } else {
            int maxR = *max_element(R.end() - 6 , R.end());
            R.push_back(A[i] + maxR);
        }
    }
    return R[aLen-1];
}


/* 기억 : max_element 문법
주의 : min_element()나 max_element()는 iterator(반복자)를 반환한다.
    따라서 값을 가져올 때에는 "*" 를 잊지 말아야 한다.

예시코드 :
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

int main()
{
    std::vector<int> vecData = { 1, 5, 3, 6, 8, 3, 2, 9 };  
    int arrData1[] = { 1, 5, 3, 6, 8, 3, 2, 9 };
    std::array<int, 8> arrData2 = { 1, 5, 3, 6, 8, 3, 2, 9 };
    
    int minElement1 = *std::min_element(vecData.begin(), vecData.end());                // 1
    int minIndex = std::min_element(vecData.begin(), vecData.end()) - vecData.begin();  // 2
    int maxElement1 = *std::max_element(vecData.begin() + 1, vecData.begin() + 3);      // 3
    int minElement2 = *std::min_element(arrData1, arrData1 + 8);                        // 4
    int minElement3 = *std::min_element(arrData2.begin(), arrData2.end());              // 5
    
    return 0;
}


*/