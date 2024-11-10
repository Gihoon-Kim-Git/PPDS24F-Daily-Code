#include <stdio.h>

int adding(int sum, int number) {
    if (number == 1) return sum + 1;
    if (number == 2) return sum + 2;
    if (number == 3) return sum + 4;
    sum = adding(sum, number - 1);
    sum = adding(sum, number - 2);
    sum = adding(sum, number - 3);
    return sum;
}

int main() {
    int count;
    scanf("%d", &count);
    for (int i=0; i<count; i++) {
        int number;
        scanf("%d", &number);
        printf("%d\n", adding(0, number));
    }
    
    return 0;
}