int reverseBits(int n) {
    int num = 31;
    int ans = 0;
    while(n!=0){
        if(n&1==1) ans += pow(2,num);
        n = n >> 1;
        num--;
    }
    return ans;
}