#include <stdio.h>
#include <iostream>
using namespace std;

int summation(int n, int total){

    if(total < 0){return 0;}
    if(total == 1){return 1;}
    if(total == 2){return 2;}
    if(total == 3){return 4;}

    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += summation(n, total-i);
    }
    
    return sum;
}

int main() {
    int n, total;
    cin >> n >> total;
    cout << summation(n, total) << endl;
}