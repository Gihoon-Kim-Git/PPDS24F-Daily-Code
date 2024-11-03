#include <bits/stdc++.h>
using namespace std;


int solution(vector<int> &A) {
    int len = A.size();
    int sum = 0;
    int tmp = 0;
    if(len<2) return 0;
    vector<int> cha(len-1);
    for(int i=0;i<len; i++){
        cha[i] = A[i+1] - A[i];
    }
    for(int i=0;i<cha.size(); i++){
        tmp += cha[i];
        if(tmp<0) tmp = 0;
        if(tmp>sum) sum = tmp;
    }
    return sum;
}