#include <bits/stdc++.h>
#include <array>
using namespace std;


int solution(vector<int> &A) {
    int ans = -INT_MAX;
    vector<int> B;

    sort(A.begin(), A.end(), greater<int>());
    B.push_back(A[0]);
    B.push_back(A[1]);
    B.push_back(A[2]);

    if(A.size()==4){
        B.push_back(A[3]);
    }
    else if(A.size()==5){
        B.push_back(A[3]);
        B.push_back(A[4]);
    }
    else if(A.size()>5){
        sort(A.begin(), A.end());
        B.push_back(A[0]);
        B.push_back(A[1]);
        B.push_back(A[2]);
    }
    // cout<<"B[0]: "<<B[0]<<"B[1]: "<<B[1]<<"B[2]: "<<B[2]<<"B[3]: "<<B[3]<<"B[4]: "<<B[4]<<endl;
    
    int bsize = B.size();

    for(int i=0; i< bsize; i++){
        for(int j=i+1; j< bsize; j++){
            for(int k=j+1; k< bsize; k++){
                // cout<<B[i]<<B[j]<<B[k]<<endl;
                if(B[i]*B[j]*B[k] > ans) ans = B[i]*B[j]*B[k];
                // cout<<ans<<endl;
            }        
        }
    }
    
    return ans;
}


// int main(void){
//     vector<int> A = {-10,-2,-4};
//     cout<< solution(A)<< endl;
// }



// int solution(vector<int> &A) {
//     sort(A.begin(), A.end(), greater<int>());

//     return A[0]*A[1]*A[2];
// }

