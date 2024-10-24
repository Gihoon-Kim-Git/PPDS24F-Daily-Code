// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int K, int A[], int N) {
    // Implement your solution here
    int ans = 0;
    int curr = 0;
    for(int i=0;i<N;i++){
        curr += A[i];
        if(curr>=K){
            ans++;
            curr = 0;
        }
    }
    return ans;
}
