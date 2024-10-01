#include <stdio.h>

int func1(int a){
    int arr[a+1] = {1};
    for(int j=1;j<a+1;j++){
        if(j>=1) arr[j]+=arr[j-1];
        if(j>=2) arr[j]+=arr[j-2];
        if(j>=3) arr[j]+=arr[j-3];
    }
    return arr[a];
}
int main(){
    int n; // test case 개수
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        printf("%d\n",func1(num));
    }    
    return 0;
}