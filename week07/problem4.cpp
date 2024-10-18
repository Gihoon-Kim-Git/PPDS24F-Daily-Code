#include <algorithm>
#include <vector>
using namespace std;

int summa(vector<int>& a){
    int ans = 0;
    for(auto& it : a){
        ans += it;
    }
    return ans;
}

int maxima(vector<int>& a){
    int ans = -1;
    for(auto& it : a){
        ans = max(it, ans);
    }
    return ans;
}

bool validblock(vector<int>& a, int k, int mid){
    int blocksum = 0;
    int blockcnt = 1; 
    
    for(auto& it : a){
        if(blocksum + it > mid){
            blocksum = it;
            blockcnt += 1;
            if(blockcnt > k){ 
                
                return false;
            }
        } else {
            blocksum += it;
        }
    }
    return true;
}

int bst(int k, int m, vector<int>& a){
    int lower = maxima(a);
    int upper = summa(a);
    if(k == 1) return upper;  
    
    if(k >= a.size()) return lower; 
    
    
    while(lower <= upper){
        int mid = (lower + upper) / 2;
        if(validblock(a, k, mid)){
            upper = mid - 1;  
            
        } else {
            lower = mid + 1;  
            
        }
    }
    
    return lower;
}

int solution(int K, int M, vector<int>& A) {
    // Implement your solution here
    return bst(K, M, A);
}