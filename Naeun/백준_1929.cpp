#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int s, f;

int isPrime(int n){
    if(n == 1)
        return 0;
    
    int x = (int)sqrt(n);
    
    for(int i=2; i<=x; i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}


int main(void) {
    
    cin >> s >> f;
    
    for(int i=s; i<=f; i++){
        if(isPrime(i))
            printf("%d\n", i);
    }
    
    return 0;
}
