// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(char *S) {
    // Implement your solution here
    if(!S) return 1;
    int n = strlen(S);
    char arr[n];
    int idx = 0;

    for(int i=0;i<n;i++){
        if(S[i]==')'){
            if(idx > 0 && arr[idx-1] == '('){
                idx--;
                continue;
            }else return 0;
        }
        if(S[i]=='}'){
            if(idx > 0 && arr[idx-1] == '{'){
                idx--;
                continue;
            }else return 0;
        }
        if(S[i]==']'){
            if(idx > 0 && arr[idx-1] == '['){
                idx--;
                continue;
            }else return 0;
        }
        else{
            arr[idx++] = S[i];
        }
    }
    if(idx==0) return 1;
    else return 0;
}