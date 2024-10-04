#include <stdlib.h>
#include <stdio.h>

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i ++) {
        printf("%d\n",arr[i]);
    }
}
int div123(int A) {
    if ((A == 0) || (A == 1)) {
        return 1;
    } else if (A==2) {
        return 2;
    } else if (A==3) {
        return 4;
    }
    return div123(A-1) + div123(A-2) + div123(A-3);
}
int* numMethods(int* arr, int size) {
    int* cnt_list = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i ++) {
        cnt_list[i] = div123(arr[i]);
    }   
    return cnt_list;
}

int main() {
    int N;
    scanf("%d",&N);
    int* int_list = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d",&(int_list[i]));
    }
    int* result = numMethods(int_list, N);
    print_arr(result, N);
    return 0;
}