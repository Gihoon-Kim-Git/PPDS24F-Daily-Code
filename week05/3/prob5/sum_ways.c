// This program calculates the number of ways to represent a given integer 'n'
// as the sum of the integers 1, 2, and 3, using a recursive approach.
// For each test case, the program receives an integer 'n' (1 <= n <= 10),
// and outputs how many distinct ways 'n' can be expressed as a sum of 1, 2, and 3.
// For example, for n = 4, the valid combinations are:
// 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2, 1+3, and 3+1, resulting in 7 ways.

#include <stdio.h>

int sum_ways(int n) {
    if (n==1) {
        return 1;
    } else if (n==2) {
        return 2;
    } else if (n==3) {
        return 4;
    } else {
        return sum_ways(n-1) + sum_ways(n-2) + sum_ways(n-3);
    }
}

int main() {
    int T, n;
    printf("Enter number of test cases: ");
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        printf("%d\n", sum_ways(n));
    }

    return 0;
}