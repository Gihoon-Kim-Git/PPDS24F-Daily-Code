// Sort Characters By Frequency in C

char* frequencySort(char* s) {
        int arr[128]={0};
    int k=0;
    while(s[k]){
        arr[(s[k])]++;
        k++;
    }
    char *ans=calloc(k+1,sizeof(char));
    int j =0;
    while(j<k){
        int max=0;
        for(int i=0;i<128;i++){
            if(arr[max]<arr[i]){
                max=i;
            }
        }
        for(int i=arr[max];i>0;i--){
            ans[j++] = (char)(max);
        }
        arr[max]=0;
    }

    return ans;
}