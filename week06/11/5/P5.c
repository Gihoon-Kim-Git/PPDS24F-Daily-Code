#include <stdio.h>
#include <stdlib.h>

int maxNumberOfBalloons(char* text) {
    int dic[5] = {0};
    int i = 0;
    int lflag = 0;
    int oflag = 0;
    while(text[i]){
        if (text[i] == 'b'){
            dic[0]++;
        }
        else if(text[i] == 'a'){
            dic[1]++;
        }
        else if(text[i] == 'l' && lflag == 1){
            dic[2]++;
            lflag = 0;
        }
        else if(text[i] == 'l'){
            lflag = 1;
        }
        else if(text[i] == 'o' && oflag == 1){
            dic[3]++;
            oflag = 0;
        }
        else if(text[i] == 'o'){
            oflag = 1;
        }
        else if(text[i] == 'n'){
            dic[4]++;
        }
        i++;
    }

    int min = INT32_MAX;
    for(int i = 0; i< 5; i++){
        if(dic[i] < min){
            min = dic[i];
        }
    }
    return min;
}


int main(void){
    char* text = "loonbalxballpoon";
    printf("%d", maxNumberOfBalloons(text));
    return 0;
}