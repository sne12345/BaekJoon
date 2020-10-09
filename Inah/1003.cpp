#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int t, n;
	int dp[41] = {0, 1, 1};
	
	for (int i = 3; i < 41; i++) dp[i] = dp[i-1] + dp[i-2];
	
	scanf("%d", &t);
	
	for(int i = 0; i < t; i++) {
		scanf("%d", &n);
	    if(N == 0) printf("%d %d\n", 1, 0);
	    else if (N == 1) printf("%d %d\n", 0, 1);
	    else printf("%d %d\n", dp[n-1], dp[n]);
	}
}
