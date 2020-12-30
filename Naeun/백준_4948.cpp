#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int cnt = 0;
int var;

int isPrime(int num){
    if(num == 1)
        return 0;
    
    int x = (int)sqrt(num);
    for(int i=2; i<=x; i++){
        if(num % i == 0)
            return 0;
    }
    return 1;
}

int countPrime(int input){
    for(int i=input+1; i<=input*2; i++){
        if(isPrime(i))
            cnt++;
    }
    return cnt;
}

int main(void) {
    
    while(1){
        cin >> var;
        if(var == 0)
            break;
        
        cnt = 0;
        printf("%d\n", countPrime(var));
    }
    
    return 0;
}
