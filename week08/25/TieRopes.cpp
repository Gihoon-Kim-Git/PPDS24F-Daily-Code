#include <iostream> 
#include <vector>

using namespace std;

int solution(int K, vector<int> &A) {
    int count = 0;          
    int current_length = 0;  

    for (int i = 0; i < A.size(); i++) {
        current_length += A[i];  

        if (current_length >= K) {
            count++;             
            current_length = 0;
        }
    }

    return count;
}