/*Quick Sort
    : 이 문제에서는, last element를 pivot으로, low와 high를 관리하는 형태로.
*/

/* 수도코드
    1. QuickSort (Conquer)
        pivot을 기준으로 왼쪽은 작은 값들, 오른쪽은 큰 값들로 정리.
    2. partition (Divide)
        Base case : len(arr)가 0 ||1일때.
        Recursive : 이외. pivot을 기준으로 왼쪽, 오른쪽. (pivot 제외)

*/

/* First element가 pivot
    1. pivotVal = arr[low]
    2. i = low, j = high
    3. i,j가 교차할 때까지 반복. (i는 pivotVal보다 큰 값을 찾을 때까지 i++, j는 pivot보다 작은 값을 찾을 때 까지 j--)
    4. i,j가 교차하기 전에 swap. 
    5. 마지막에 arr[j]와 pivotVal을 교환. 
    6. return j 
*/

/* Last element가 pivot
    1. pivotVal = arr[high]
    2. i = low-1, j = high-1
    3. i는 pivotVal보다 큰 값을 찾을때까지 i++
        j는 pivotVal보다 작은 값을 찾을 때까지 j--
        i, j가 둘다 멈췄을 때 여전히 i< j (역전 전)이면 swap
    4. i+1과 pivot을 교환
    5. return i+1
*/

#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int low, int high){
    if (low < high) {
        int new_pivot = partition(arr, low, high);
        quickSort(arr, low, new_pivot-1);
        quickSort(arr, new_pivot+1, high);
        return;
    }
}

//partition1 : for문 활용 (Last element가 pivotVal)
int partition(int arr[], int low, int high){
    int pivotValue = arr[high]; // last element가 pivot
    int i = low-1 ; //pivot보다 작은 요소의 마지막 인덱스를 추적

    for (int j = low; j < high; j++){
        if (arr[j] <= pivotValue){
            i++;
            //피벗보다 작은 요소 발견 시 i++, arr[i], arr[j] 교환
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //피벗위치 이동(pivot보다 작은 요소의 다음 자리가 pivot의 위치가 되어야 함.) 
    // + high 자리에에 있던 pivot값을 가야할 자리로 이동시켜줌.
    int temp2= arr[i+1]; 
    arr[i+1] = arr[high];
    arr[high] = temp2;
    return i+1;
}

//partition2 : while문 활용 (First element가 pivotVal)
int partition(int arrp[], int low, int high){
    int pivotVal = arr[low];
    int i = low; //i : pivotVal보다 큰 원소 찾기위해 배열 왼->오로 이동.
    int j = high; // j : pivotVal보다 작은 원소 찾기 위해서 배열 오->왼쪽으로 이동.

    while (i < j){
        while (arr[i] <= pivotVal && i <= high-1) i++; // i가 마지막원소(arr[high])를 넘어서지 않도록)
        while (arr[j] >= pivotVal && j >= low+1) j--; //j가 pivot위치 다음까지 움직이도록.
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp2 = arr[low];
    arr[low] = arr[j];
    arr[j] = temp2;

    return j;
}






//-------<틀린 나의 풀이>--------------------------------

#include <stdio.h>
#include <stdlib.h>

//들어온 partition을 pivot 기준으로 정렬하는 함수 : 반환하는 값은 피벗의 위치(index)를 반환.
int partition (int arr[], int low, int high){

    //1. pivot 선정 (last element로)
    int pivot = high;
    high--;
    //2. low, high를 움직인다.  (low가 멈추면 high를 움직이도록.)
    while (low < high){ // low >= high일 때 while문 탈출
        if (arr[low] <= arr[pivot]) low++;
        else { //이 때 low가 멈춤. 이제 high를 움직일 차례.
            while (arr[high] > arr[pivot]) high--;
            if (arr[low] > arr[pivot] && arr[high] <= arr[pivot]){
                int temp = arr[low];
                arr[low] = arr[high];
                arr[high] = temp;
            }
        }
    }
    /*while 문 이하를 아래와 같이 바꾸어 줄 수 있음 : main은 통과하지만... 반례) 24 18 38 43 14 40 1 54  (피벗이 최댓값인 경우...)
    while (low < high){ // low >= high일 때 while문 탈출
        while (low < high && arr[low] <= arr[pivot]) low++;
        while (low < high && arr[high] >= arr[pivot]) high--;
        if (low < high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }*/


    //3. low, high에 대한 정렬이 끝나면 pivot과 high자리의 요소를 바꿔줌.(그럼 high가 new_pivot이 됨.)
    int tempP = arr[pivot];
    arr[pivot] = arr[high];
    arr[high] = tempP;

    //printf("new_pivot : %d", high);
    return high; // 이부분이 잘못되었음. 졍렬된 pivot의 새 위치를 반환해야 함.
}



// 세 개의 param을 받아서 partitions를 나누는 함수.: partition은 무엇을 반환하는 것인지 ? 아무래도 정렬이 끝난 후 high 값을 반환하는 거 같다.
void quickSort(int arr[], int low, int high){
    //int arr_len = sizeof(arr)/sizeof(arr[0]);
    printf("quickSort called.");
    //Base case
    if (high-low <= 0 ) return; // high-low ==0인 경우가 부분 배열 길이가 1인 경우. high-low == 1인 경우는 부분 배열의 길이가 2인 경우임.


    //Recursive case : left([]:high]), right([low:])
    if (low < high){ //이 조건이 없으면 무한 루프를 돌게된다... (이 조건이 false : 길이가 0 또는 1)
        int new_pivot = partition(arr, low, high);
        //new pivot 좌 우로.
        quickSort(arr, low, new_pivot-1);
        quickSort(arr, new_pivot+1, high);
        return;
    }
}


int main(){
    int arr[] = {4,1,3,9,7};
    int low = 0;
    int high = 4;
    quickSort(arr,low, high);

    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }

    //ex2
    int arr2[] = { 2, 1, 6, 10, 4, 1, 3, 9, 7};
    int low2 = 0;
    int high2 = 8;
    quickSort(arr2,low2, high2);

    for (int i = 0; i < 8; i++){
        printf("%d ", arr2[i]);
    }
}

/*내 코드 돌린 결과 : ex2가 제대로 sort되지 않음. (이유 : partition 함수의 논리 오류. while 문.)
quickSort called.new_pivot : 3quickSort called.new_pivot : 1quickSort called.quickSort called.quickSort called.1 3 4 7 9 quickSort called.new_pivot : 6quickSort called.new_pivot : 1quickSort called.quickSort called.new_pivot : 1quickSort called.quickSort called.new_pivot : 4quickSort called.quickSort called.quickSort called.1 2 1 3 6 4 7 9*/