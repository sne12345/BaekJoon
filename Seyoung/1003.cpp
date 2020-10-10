#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;
int dp[41];

int fibonacci(int n) {

	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}else if(n < 0)
     return 1;
	else {
		if (dp[n] > 0) return dp[n];
		dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return dp[n];
	}
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);
	int n, r;
	int one;
    int zero;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		
		memset(dp, 0, sizeof(dp));
		scanf("%d", &r);
		one = fibonacci(r);
		zero = fibonacci(r-1);
		
		printf("%d %d\n", zero, one);
	}
	
}
