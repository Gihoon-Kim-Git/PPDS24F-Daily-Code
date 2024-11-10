#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
 
int dp[11] = { 0,1,2,4 };
 
int main() {
	int T, n, t, i;
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d", &n);
		for (i = 4; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		printf("%d\n", dp[n]);
	}
	return 0;
}