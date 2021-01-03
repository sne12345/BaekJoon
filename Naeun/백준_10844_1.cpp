#include <stdio.h>
#include <iostream>
#define MAX_INT 1000000000
using namespace std;

int N;
long long int cnt = 0;
long long int dp[101][11];

int main(void) {
    
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    
    for(int i=1; i<=9; i++){
        dp[1][i] = 1;
    }
    
    for(int i=2; i<=N; i++){
        for(int j=0; j<=9; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j+1] % MAX_INT;
            } else if(j == 9) {
                dp[i][j] = dp[i-1][j-1] % MAX_INT;
            } else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MAX_INT;
            }
        }
    }
    
    for(int i=0; i<=9; i++){
        cnt += dp[N][i];
    }
    
    printf("%lld\n", cnt % 1000000000);
    
    return 0;
}
