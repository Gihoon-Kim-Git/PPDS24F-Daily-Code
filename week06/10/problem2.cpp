#include <iostream>
#include <vector>

using namespace std;

int result = 0;
int temp;

int solution(vector<int> &A) { 
    
    result = A[0] + A[5];
    
    for(int i=1; i<5; i++){
        temp = result + A[i];
        if (temp > result){
            result += A[i];
        }
    }
    return result;
}


int main(void) {
        
    vector<int> b1;
    b1.push_back(1);
    b1.push_back(-2);
    b1.push_back(0);
    b1.push_back(9);
    b1.push_back(-1);
    b1.push_back(-2);

    vector<int> b2;
    b2.push_back(-1);
    b2.push_back(2);
    b2.push_back(3);
    b2.push_back(-4);
    b2.push_back(5);
    b2.push_back(6);


    cout << solution(b1) << endl;
    cout << solution(b2) << endl;    

    return 0;
}