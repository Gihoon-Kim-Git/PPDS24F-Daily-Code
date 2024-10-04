#include <iostream>
#include <cstring> //memset

using namespace std;

/*
integer 4개를 
1,2,3의 합으로 나타내는 방법은 총 7가지 
합을 나타낼 떄는 수를 1개 이상 사용
11 > int n > 0 이 주어졌을 때
n = 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그래을 작성

input: 
1st line = T
각각의 n은 한 줄로 이루어져 있고 

recursive 사용해서 풀기 
recurrence relation(점화식)사용하기 이렇게 
(풀이 보니까 DP로 풀어야... )
점화식 한 번 스스로 찾아보기 
*/

int n;
int arr[12];

int dp(int num) {
    // base case
    if (num == 1) return 1;
    if (num == 2) return 2;
    if (num == 3) return 4;

    // memorization
    if (arr[num] != -1) return arr[num];
    return arr[num] = dp(num-1) + dp(num-2) + dp(num-3);
}

int main(){

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int T;
   cin >> T;
   while(T--){
    cin >> n;
    memset(arr, -1, sizeof(arr));
    cout << dp(n) << '\n';
   }
    return 0;
}