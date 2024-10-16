/*문제
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers
*/

/*문제풀이 1: recursive
    1. base case : rowIndex == 0 || rowIndex == 1 
    2. recursive case : row[i] = prev[i-1] + prev[i]
*/

/*문제풀이2 : Iterative
    1. prev, temp를 활용한다. prev를 이용한 temp 한 사이클이 끝나면, prev = temp로 update.
    2. 초기 prev = []
    3. temp를 i번 update.
        for loop : i = 0 ~ rowIndex
            temp[0] = [1]
            temp[i] = 1
            중간값 업데이트
            for loop : j = 1 ~ (i-1)
                temp[j] = prev[j-1] + prev[j]
            prev = temp
    4. retrn temp
*/

#include <iostream>
#include <vector>
using namespace std;

//문제풀이1 : recursive
class Solution{
public:
    vector<int> getRow(int rowIndex){
        vector<int> result(rowIndex+1,1); // 1로 rowIndex+1개만큼 요소 로 초기화

        //base case
        if (rowIndex == 0 || rowIndex == 1) {
            return result;
        }
        
        //recursive
        vector<int> prev = getRow(rowIndex-1);
        for (int i = 1; i < rowIndex; i++){
            result[i] = prev[i-1] + prev[i];
        }

        return result;
    }
};

//문제풀이2 : iterative
class Solution{
public:
    vector<int> getRow(int rowIndex){
        vector<int> prev = {};

        for (int i = 0; i <= rowIndex; i++){
            vector<int> temp(i+1, 0);
            temp[0] = 1;
            temp[i] = 1;
            for (int j = 1; j < i; j++){
                temp[j] = prev[j-1] + prev[j];
            }
            prev = temp;
        }
        return prev;
    }
};

//문제풀이3 : iterative
class Solution{
public:
    int* getRow(int rowIndex){
        int* cur = new int[rowIndex + 1];  // 새로운 정수 배열을 동적으로 할당
        cur[0] = 1;  // 첫 번째 요소는 항상 1

        for (int i = 1; i <= rowIndex; i++) {
            cur[i] = 1;  // 매 행의 마지막 요소는 항상 1
            for (int j = i - 1; j > 0; j--) {
                cur[j] = cur[j - 1] + cur[j];  // 역순으로 중간 값을 업데이트
            }
        }
        return cur;  // 동적으로 할당된 배열의 포인터 반환
    }
};


int main(){
    int rowIndex = 3;
    Solution sol1;
    vector<int> result = sol1.getRow(rowIndex);

    cout << "[";
    for (int i : result) {
        cout << i << " " ;
    }
    cout << "]";

    return 0;
}

