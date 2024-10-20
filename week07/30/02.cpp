#include <iostream>
using namespace std;

// [1] partition 함수: 배열을 분할하여 피벗을 기준으로 왼쪽엔 작은 값, 오른쪽엔 큰 값들이 오도록함.
int partition(int arr[], int low, int high) {
    // [1.1] 피벗으로 마지막
    int pivot = arr[high];
    // [1.2] 작은 값들의 마지막 인덱스추적할 i
    int i = low - 1;

    // [1.3] 피벗보다 작은 요소들을 왼쪽으로 이동
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; // 작은 값을 찾으면 i를 증가시키고
            swap(arr[i], arr[j]); // i와 j 위치의 값들을 교환
        }
    }

    // [1.4] 피벗을 올바른 위치로 이동
    swap(arr[i + 1], arr[high]);
    // [1.5] 피벗의 최종 위치 반환
    return (i + 1);
}

// [2] quickSort 함수: 분할 & 정렬
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // [2.1] partition 함수로 피벗의 올바른 위치 찾기
        int pi = partition(arr, low, high);

        // [2.2] 피벗 왼쪽
        quickSort(arr, low, pi - 1);
        // [2.3] 피벗 오
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;
    
    int arr[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, N - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;  // [6] 프로그램 종료
}
