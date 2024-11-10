#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int i;
        for(i=0; n>0; n&= n-1){
            i = -(i+(n^(n-1)));
        }
        return abs(i);
    }
};