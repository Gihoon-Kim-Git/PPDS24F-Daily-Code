#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int maxNumberOfBalloons(char* text) {
    int b = 0, a = 0, l = 0, o = 0, n = 0, result = INT_MAX;
    for (int i=0; i<strlen(text); i++) {
        if (text[i] == 'b') b++;
        if (text[i] == 'a') a++;
        if (text[i] == 'l') l++;
        if (text[i] == 'o') o++;
        if (text[i] == 'n') n++;
    }
    if (b < result) result = b;
    if (a < result) result = a;
    if (l/2 < result) result = l/2;
    if (o/2 < result) result = o/2;
    if (n < result) result = n;
    return result;
}

int main() {
    char t1[] = "nlaebolko";
    char t2[] = "loonbalxballpoon";

    printf("%d\n", maxNumberOfBalloons(t1));
    printf("%d\n", maxNumberOfBalloons(t2));

    return 0;
}