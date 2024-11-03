// you can use includes, for example:
#include <vector>
#include <algorithm>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int maxProfit = 0;

    // minPriceYesterday = min(A[:i-1])
    int potentialMaxProfit;
    int minPriceYesterday = 200000;
    for(size_t i=1; i<A.size(); i++) {
        // 어제까지의 최소 = min(그저께까지의 최소, 어제 가격)
        minPriceYesterday = min(minPriceYesterday, A[i-1]);
        // maxProfit 의 후보 : 오늘 판다는 가정하에 얻을 수 있는 최대 수익
        // = 오늘 가격 - 어제까지의 최소가격
        potentialMaxProfit = A[i] - minPriceYesterday;
        if (potentialMaxProfit > maxProfit) {
            maxProfit = potentialMaxProfit;
        }
    }
    
    return maxProfit;
}
