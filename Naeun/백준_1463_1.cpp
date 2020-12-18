#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX_NUM 1000001

int DP[MAX_NUM];

int main(void) {
    
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<=n; i++){
        DP[i] = MAX_NUM;
    }
    
    DP[n] = 0;
    for(int i=n; i>0; i--){
        if(i % 3 == 0){
            DP[i/3] = min(DP[i/3], DP[i] + 1);
        }
        if(i % 2 == 0){
            DP[i/2] = min(DP[i/2], DP[i] + 1);
        }
        
        DP[i-1] = min(DP[i-1], DP[i] + 1);
    }
    
    printf("%d\n", DP[1]);
    
    return 0;
}
