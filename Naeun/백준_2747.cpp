
#include <iostream>
#include <stdio.h>

int Fibo[46];

int main(void) {
    
    int n;
    
    Fibo[0] = 0;
    Fibo[1] = 1;
    
    scanf("%d", &n);
    
    for(int i=2; i<=n; i++){
        Fibo[i] = Fibo[i-1] + Fibo[i-2];
    }
    printf("%d\n", Fibo[n]);
    
    return 0;
}
