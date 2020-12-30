#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int n, x;
int total;

int isPrime(int num){
    if(num == 1)
        return 0;
    int y = (int)sqrt(num);
    
    for(int i=2; i<=y; i++){
        if(num % i == 0)
            return 0;
    }
    return 1;
}

int main(void) {
    
    cin >> total;
    
    for(int j=0; j<total; j++){
    
        cin >> n;
        x = n / 2;

        for(int i=x; i>0; i--){
            if(isPrime(i) && isPrime(n-i)){
                printf("%d %d\n", i, n-i);
                break;
            }
        }
    }
    
    return 0;
}
