#include <stdio.h>
#include <stdlib.h>

int minimumOneBitOperations(int n) {
    //base case
    if (n==0) {
        return 0;
    }

    //젤 높은 위치 bit 찾기(가장 큰 1 bit 위치)
    int hbp = 0; //highest_bit_pos
    while ((1 << hbp) <= n) {
        hbp++;
    }
    hbp--;

    return (1 << hbp) + minimumOneBitOperations(n ^ (1 << hbp) ^ (1 << (hbp - 1)));
}

int main() {
    int n1 = 3;
    int n2 = 6;

    printf("input %d; output %d\n", n1, minimumOneBitOperations(n1));
    printf("input %d; output %d\n", n2, minimumOneBitOperations(n2));

    return 0;
}
