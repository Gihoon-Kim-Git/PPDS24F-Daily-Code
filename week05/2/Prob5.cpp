#include <iostream>
using namespace std;

int sum123(int num){
    if(num == 1){
        return 1;
    }else if(num == 2){
        return 2;
    }else if(num == 3){
        return 4;
    }else{
        return sum123(num-1) + sum123(num-2) + sum123(num-3);
    }
}

int main(){
    int T, num;

    cin >> T;
    
    for(int i = 0; i < T; i++){
        cin >> num;
        cout << sum123(num) << endl;
    }
    return 0;
}
