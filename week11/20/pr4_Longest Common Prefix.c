char* longestCommonPrefix(char** strs, int strsSize) {
    int len = strlen(strs[0]);
    char* ans = (char*)malloc(200*sizeof(char));
    char* temp = strs[0];
    int idx = 0;
    for(int i=0;i<len;i++){
        idx = i;
       for(int j=0;j<strsSize;j++){
        if(i == strlen(strs[j])||strs[j][i]!=temp[i]){
            ans[idx] = '\0';
            return ans;
        }
       }
       ans[i] = temp[i];
    }
    return temp;
}