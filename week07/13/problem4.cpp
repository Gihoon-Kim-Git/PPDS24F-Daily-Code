// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, int M, vector<int> &A) {
    // Implement your solution here

    // Implement your solution here

        // Step 1: Binary Search Range:

        // The minimum possible value of the maximum sum (lowerBound) is the largest element in the array (max(A) = 5).
        // The maximum possible value (upperBound) is the sum of all elements (sum(A) = 15).

        // Step 2: First mid Calculation:

        // mid = (lowerBound + upperBound) / 2 = (5 + 15) / 2 = 10.
        // Now we check if it's possible to split the array into 3 blocks where no block sum exceeds 10.

        // Step 3: Greedy Check for mid = 10:

        // Start with the first block:
        // Block 1: Add 2, 1, 5 (sum = 8), add 1 (sum = 9). Adding 2 would exceed 10, so start a new block.
        // Block 2: Add 2 (sum = 2), add 2 (sum = 4), add 2 (sum = 6). All elements are processed, and we used 2 blocks.
        // Since we could split the array into 2 blocks (fewer than 3), we know that mid = 10 is valid, but we can try a smaller value.

        // Step 4: Update Binary Search:

        // Since we succeeded with 10, we try a smaller maximum sum, so set upperBound = mid - 1 = 9.
        // Continue this process until you find the minimal large sum.

    int lower=*max_element(A.begin(), A.end());  
    int upper=0;
    
    for(int i=0; i<A.size(); i++){
        upper+=A[i];
    }
    
    while(lower<=upper){
        int mid=(lower+upper)/2;
        vector<int> check(K+1, 0);
        int cur=0;
        
        for(int j=0; j<A.size(); j++){
            if(check[cur]+A[j]<=mid){
                check[cur]+=A[j];
            }
            else
            {
                cur++;
                if(cur==K){
                    break;
                }
                check[cur]+=A[j];
            }
        }
        if(cur==K){
            lower=mid+1;
        }
        else{
            upper=mid-1;  
        }
    }

    return lower;

}
