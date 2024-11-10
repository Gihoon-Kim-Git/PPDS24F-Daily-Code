// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here

    //A[1-6]중 가장 큰 값 - A[0]
    //A[2-6]중 가장 큰 값 - A[1]
    // ....
    //A[6]-A[5]
    //min값을 A[n]으로 잡고 재귀적으로 부르면서 계속 바꿔가면 될듯
    
    //0인 것 처리

    if(A.size()==0){
        return 0;
    }

    //음수인 경우 처리
    
    int max=A[A.size()-1];
    int profit=A[A.size()-1]-A[A.size()-2];

    for(auto cur=A.size()-1; cur>=1; cur--){
        if(A[cur]>max){
            max=A[cur];
        }
        if(max-A[cur-1]>profit){
            profit=max-A[cur-1];
        }
    }

    if(profit<0){
        return 0;
    }
    return profit;
}
