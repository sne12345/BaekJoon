#include <stdio.h>
#include <iostream>
using namespace std;

int N;

int divideSum(int num){
    int answer = num;
    
    while(num > 0){
        answer += num % 10;
        num /= 10;
    }
    return answer;
}

int main(void) {
    
    cin >> N;
    
    for(int i=1; i<N; i++) {
        if(divideSum(i) == N){
            printf("%d\n", i);
            return 0;
        }
    }
    
    printf("0\n");
    
    return 0;
}
