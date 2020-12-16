
#include <iostream>
#include <stdio.h>

int arr[9999];
int arrId = 0;

int isIn(int n){
    if(arrId > 0){
        for(int i=0; i<arrId - 1; i++){
            if(arr[i] == n){
                arrId = i;
                return 1;
            }
        }
    }
    return 0;
}

int dfs_mul(int num, int P){
    if(P <= 0){
        return 1;
    } else {
        return num * dfs_mul(num, P - 1);
    }
}

void dfs(int num, int P){
    
    if(isIn(num)){
        return;
    } else {
        int newNum = 0;
        
        while(num > 0){
            newNum += dfs_mul(num % 10, P);
            num /= 10;
        }
//        printf("%d\n", newNum);
        
        arr[arrId++] = newNum;
        dfs(newNum, P);
    }
}

int main(void) {
    
    int num, P;
    
    scanf("%d %d", &num, &P);
    arr[arrId++] = num;
//    printf("%d\n", num);
    dfs(num, P);
    
    printf("%d\n", arrId);
    
    return 0;
}
