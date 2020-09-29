#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <stdlib.h>
using namespace std;

int col[15], cnt = 0;
int n;

int is_not_Queen(int num){
    for(int i=0; i<num; i++){
        if(col[i] == col[num] || abs(col[num]-col[i]) == (num-i))
            return 0;
    }
    return 1;
}

void D(int m){
    if(m == n){
        cnt++;
    } else {
        for(int i=0; i<n; i++){
            col[m] = i;
            if(is_not_Queen(m)){
                D(m+1);
            }
        }
    }
}

int main(void) {
    scanf("%d", &n);
    
    D(0);
    printf("%d\n", cnt);
    
    return 0;
}
