#include <bits/stdc++.h>
#include <vector>
using namespace std;


int solution(int K, vector<int> &A) {
    // Implement your solution here
    int len = A.size();
    int temp = 0;
    int ans = 0;
    for(int i=0; i<len; i++){
        temp += A[i];
        if(temp>=K) {
            ans++;
            temp = 0;
        }
        
    }
    return ans;
}

// int main(void){
//     vector<int> A = {1,2};
//     cout<<solution(4, A)<<endl;
// }