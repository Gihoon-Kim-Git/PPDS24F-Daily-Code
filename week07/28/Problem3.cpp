// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>

int solution(vector<int> &A) {
    // Implement your solution here
    if(A.size() < 3){return 0;}
    int max = -10000;

    for(auto x : A){
        for(auto y : A){
            if (x == y){continue;}
            for(auto z : A){
                if(x == z || y == z){continue;}
                if(x * y * z > max){
                    max = x * y * z;
                }
            }
        }
    }
    
    return max;
}