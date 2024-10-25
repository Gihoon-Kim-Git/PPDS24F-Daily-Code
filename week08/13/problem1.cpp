// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int> &A) {
    // Implement your solution here

    //그럼 0번부터 K이상이 될때까지 계속 더한다
    //K이상이 되면 다음 인덱스로 넘어간다
    //인덱스 넘버 반환
    //맨 마지막 처리 주의) 맨 마지막이 남으면 cnt-1
    int sum=0;
    int cnt=1;

    for(size_t i=0; i<A.size(); i++){
        if(sum+A[i]<K){
            sum+=A[i];
        }
        else {
            cnt++;
            sum=0;
        }
    }
    if(sum==0 || sum<K){
        cnt--;
    }

    return cnt;
}
