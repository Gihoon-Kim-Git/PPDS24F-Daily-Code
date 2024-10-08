// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // Implement your solution here
    int arr[N];
    arr[0] = A[0];

    for(int i=1;i<N;i++){
        int temp = arr[i-1];
        for(int j=2;j<=6;j++){
            if(i-j>=0){
                if(temp < arr[i-j]) temp = arr[i-j];
            }
            else break;
        }
        arr[i] = temp + A[i];
    }
    return arr[N-1];
}
