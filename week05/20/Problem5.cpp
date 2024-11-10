#include <iostream>
#include <vector>
using namespace std;

int func1(int a){
    vector<int> vec(a+1,0);
    vec[0] = 1;
    for(int j=1;j<a+1;j++){
        if(j>=1) vec[j]+=vec[j-1];
        if(j>=2) vec[j]+=vec[j-2];
        if(j>=3) vec[j]+=vec[j-3];
    }
    return vec[a];
}
int main(){
    int n; // test case 개수
    cin >> n;
    for(int i=0;i<n;i++){
    int num;
    cin >> num;
    cout << func1(num) << endl;
    }
    return 0;
}