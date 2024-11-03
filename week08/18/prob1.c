# include <stdio.h>
# include <stdlib.h>

int solution(int K, int A[], int N) {
    // Implement your solution here

    int count=0;
    int sum=0;

    for (int i=0; i<N; i++){
        sum += A[i];
        if (sum >= K){
            count++;
            sum=0;
        } 
    }

    return count;
}