class Solution {
public:
    int minimumOneBitOperations(int n) {

        // if (n == 0){
        //     return 0;
        // }

        // int i = 0;
        // while ((1 << i) <= n){
        //     i++;
        // }

        // return (1 << i) - 1 - minimumOneBitOperations(n ^ (1 << (i - 1)));

        int result = 0;
        while (n > 0){
            result ^= n;
            n >>= 1;
        }

        return result;
        
    }
};