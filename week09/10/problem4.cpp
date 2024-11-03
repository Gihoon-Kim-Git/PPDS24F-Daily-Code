#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& A) {
    if (A.size() < 2) return 0;  // Not enough days to make a transaction

    int max_current = 0;
    int max_profit = 0;
    
    for (size_t i = 1; i < A.size(); ++i) {
        int diff = A[i] - A[i - 1]; 
        max_current = std::max(0, max_current + diff); 
        max_profit = std::max(max_profit, max_current); 
    }
    
    return max_profit;
}