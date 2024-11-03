int solution(vector<int> &a) {
    // Implement your solution here
    if(a.size()<2) return 0;
    int minPrice= a[0];
    int maxProfit= 0;
    int n = a.size();
    for(int i=1;i<n;i++){
        int profit= a[i]- minPrice;
        maxProfit= max(profit, maxProfit);
        minPrice= min(a[i],minPrice);
    }
    return maxProfit;
}
