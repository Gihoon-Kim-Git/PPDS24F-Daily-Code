#include <bits/stdc++.h>
using namespace std;

int check(vector<int>& A, int largest_sum) {               
    int count = 0;
    int sum = 0;
    for(size_t i =0; i <A.size(); i++){
        const int e= A[i];
        if((sum+e)>largest_sum) {
            sum = 0;
            count++;
        }
        sum +=e;
    }
    
    return count;
}


int solution(int K, int M, vector<int> &A) {
    int start = *max_element(A.begin(), A.end());
    int end = accumulate(A.begin(), A.end(), 0);
    while(start <= end){
        int mid = (start+end)/2;
        if(check(A,mid) <K) end = mid-1;
        else start = mid +1;
    }
    return start;
}
