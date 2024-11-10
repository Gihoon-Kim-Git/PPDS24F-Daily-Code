//유의사항  : returnSize다루기!

/*문제
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers
*/


/*풀이1 : recursive
    1. base case
        if rowIndex==0 : cur = [1]
    2. recursive case
        cur = [1] * (rowIndex+1)
        prev = getRow(rowIndex-1)
        for i in range(1, rowIndex)
        cur[i] = prev[i-1] + prev[i]

    rowIndex 0 [1]
            1 [1, 1]
            2 [1,2,1]
*/

/*풀이2: Iterative
    1. cur 배열 안에서 값을 계속해서 update하는 방식임.
    2. 역순 업데이트 활용:
        배열을 끝에서부터 시작하여 앞으로 업데이트. 이렇게 하면, 각 요소 계산에 필요한 이전 요소들이 아직 업데이트 되지 않은 상태라서, 올바른 값 사용 가능. cur[j-1]의 원래값을 보존하면서 cur[j]를 안전하게 계산.
*/

#include <stdio.h>
#include <stdlib.h>

//풀이1 : Recursive case  
int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex+1; // 적절한 returnSize 설정
    int* cur = (int*)malloc(sizeof(int) * (*returnSize));
    cur[rowIndex] = 1;
    cur[0] = 1;

    //base case
    if (rowIndex == 0 || rowIndex == 1) {
        return cur;
    }

    //recursive case
    int prevSize ;
    int* prev = getRow(rowIndex-1, &prevSize );
    for (int i = 1; i < rowIndex; i++){
        cur[i] = prev[i-1] + prev[i];
    }
    free(prev); // 이전 행에 대한 메모리 해제 필요.

    return cur;
}

//풀이 2 : Iterative 1
int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex+1;
    int* cur = (int*)malloc(sizeof(int) * (*returnSize));
    cur[0] = 1;

    for (int i = 1 ; i <=rowIndex;i++){
        cur[i] = 1; 
        for (int j = i-1; j > 0; j--){
            cur[j] = cur[j-1] + cur[j];
        }
    }

    return cur;
}

//풀이3 : Iterative 2 (prev, temp 활용) : prev, temp 메모리공간 관리에 특히 유의.
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex+1;

    int* prev = NULL;
    //prev에 대한 초기값을 설정하고 싶다면 아래
        //int* prev = (int*) malloc(sizeof(int));  // 최소 크기 할당
        //*prev = 1;  // 첫번째 요소 초기화, 파스칼의 삼각형에서 첫번째 요소는 항상 1
    int* temp = NULL;
    for (int i = 0; i <= rowIndex; i++){
        temp = (int*)malloc(sizeof(int) * (i+1)); // 새로운 행을 위한 메모리 할당
        temp[0] = 1;
        temp[i] = 1;

        for (int j = 1; j < i ; j++){
            temp[j] = prev[j-1] + prev[j]; //중간 요소 계산
        }
        
        free(prev); //이전 행의 메모리 해제
        prev = temp; // 현재 행을 이전 행으로 설정
    }
    return temp;
}

int main(){
    int rowIndex= 3;
    int returnSize;
    int* result = getRow(rowIndex, &returnSize);

    //결과출력
    printf("Row %d: ", rowIndex);
    for (int i = 0; i <= rowIndex; i++){
        printf("%d ", result[i]);
    }
    printf("\n");
    
    free(result);
    return 0;
}
