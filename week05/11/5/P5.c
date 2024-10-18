#include <stdio.h>
#include <stdlib.h>

int sumcount(int n){
    if (n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }
    else if(n == 3){
        return 4;
    }
    else{
        return sumcount(n-1) + sumcount(n-2) + sumcount(n-3);
    }
}

int main(void){
    int numofn = 0;
    scanf("%d", &numofn);
    for(int i = 0; i < numofn; i++){
        int k = 0;
        scanf("%d", &k);
        printf("%d\n", sumcount(k));
    }
    return 0;
}