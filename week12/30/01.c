#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [목표]
// 대문자 소문자 다르게 취급
// 젤 많이 나온애부터 출력

// [전략]
// 1. unique char*를 만들자.
// 2. 동일한 길이의 array로 기록하자.
// 3. array sort해서 차례로 
// c에서 char*는 마지막에 무조건 \0을 넣어줘야해서 malloc할때 (N+1)로 해줘야한댜!!!!!!!!!!!!!//⭐⭐⭐⭐⭐⭐

int find_max_index(int* arr, int size) {
    int max = -1;
    int max_idx = -1;
    for (int i = 0; i < size; i++) {
        if (max < arr[i]) {
            max_idx = i;
            max = arr[i];
        }
    }
    return max_idx;
}

char* frequencySort(char* s) {
//(1). [준비] uni char을 기록할거, uni char cnt를 기록할거 넣기. 
    int N = strlen(s); 
    char* uni = (char*)malloc( (N+1) * sizeof(char));
    int* uni_cnt = (int*)malloc(N* sizeof(int));
    for (int i = 0; i < N; i++) {uni_cnt[i] = 0;}
    
//(2). [하기] 기록하기. 
    int k = 0; //uni의 idx
    for (int i = 0; i < N; i++) {
        char c = s[i]; // A a b b 가 차례로 될거임
        int is_new = 1;
        //이미 있는 앤지 확인
        for (int j = 0; j < k; j++) {
            if (uni[j] == c) { //uni에 이미 있는지 확인. 
                uni_cnt[j]++;
                is_new = 0; //new 아님을 표시
            }
        }
        //new 등장이라면! k자리에 넣자. 
        if (is_new == 1) {
            uni[k] = c; 
            uni_cnt[k]++; 
            k++;
        }
    }
    uni[k] = '\0';  //⭐⭐⭐⭐⭐⭐

// //기록한거 확인
//     printf("%s\n", uni);
//     for (int i = 0; i < k; i++) {
//         printf("%c: %d\n", uni[i], uni_cnt[i]);
//     }

//(3). 젤 긴애부터 출력해보자
    //freq 높은애들부터 차례대로 기록할 곳
    char* result = (char*)malloc( (N+1) * sizeof(char));
    int result_idx = 0;
    //처리가 끝난 unique char의 개수
    int completed = 0;
    // printf("MAX IDX: %d", find_max_index(uni_cnt, k));
    while (completed < k) {
        int cur_max = find_max_index(uni_cnt, k);
        int cur_max_cnt = uni_cnt[cur_max];
        //한번 쓴다음에는 -MAX로 바꿔야겠지
        uni_cnt[cur_max]= -1;
        // printf("%c: %d\n", uni[cur_max], cur_max_cnt);
        // printf("%d - %d : %c\n", result_idx, cur_max_cnt-1, uni[cur_max]);
        for (int i = result_idx; i < cur_max_cnt+result_idx; i++) {
            result[i] = uni[cur_max];
        }
        result_idx += cur_max_cnt;
        completed++;
    }

    // printf("%s\n", result);
    free(uni_cnt);
    free(uni);

    result[N]='\0'; //⭐⭐⭐⭐⭐⭐
    return result;
}

int main() {


    char s1[100] = "tree"; // eert
    char s2[100] = "cccaaa"; 
    char s3[100] = "Aabb"; //bbaA 

    // frequencySort(s1);
    // frequencySort(s2);
    char* result3 = frequencySort(s3);
    printf("%s",result3 );
    free(result3);
    return 0;
}