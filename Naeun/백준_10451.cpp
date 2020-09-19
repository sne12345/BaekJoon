#include <stdio.h>
#include <iostream>
using namespace std;

int ch[1002], cnt = 0, flag = 0;

void D(int *arr, int n){
    if(ch[n] == 1)
        return;
    else{
        ch[n] = 1;
        D(arr, arr[n]);
    }
    
    if(flag == 0){
        flag = 1;
        cnt++;
    }
}

void init(int num){
    cnt = 0;
    for(int i=1; i<=num; i++)
        ch[i] = 0;
}

int main(void) {
    int total, num;
    scanf("%d", &total);
    
    for(int j=0; j<total; j++){
        scanf("%d", &num);
        int arr[num];
        
        init(num);
        
        for(int i=1; i<=num; i++){
            int ele;
            scanf("%d", &ele);
            arr[i] = ele;
        }
        
        for(int i=1; i<=num; i++){
            flag = 0;
            D(arr, i);
        }
        printf("%d\n", cnt);
    }
    return 0;
}
