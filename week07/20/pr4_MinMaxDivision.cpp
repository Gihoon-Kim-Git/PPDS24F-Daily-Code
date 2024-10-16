#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool checkDivisionPossible(const vector<int>& A, int K, long long maxSum) {
        int blocks = 1;
        long long currentSum = 0;
        
        for(int num : A) {
            if(num > maxSum) return false;
            
            if(currentSum + num > maxSum) {
                blocks++;
                currentSum = num;
            } else {
                currentSum += num;
            }
            
            if(blocks > K) return false;
        }
        
        return true;
    }
    
    int solution(int K, int M, vector<int> &A) {
        if(K == 1) return accumulate(A.begin(), A.end(), 0LL);
        if(K >= (int)A.size()) return *max_element(A.begin(), A.end());
        
        long long left = *max_element(A.begin(), A.end());
        long long right = accumulate(A.begin(), A.end(), 0LL);
        int result = right;
        
        while(left <= right) {
            long long mid = (left + right) / 2;
            
            if(checkDivisionPossible(A, K, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
};