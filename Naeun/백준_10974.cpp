#include <stdio.h>
#include <iostream>
#define MAX_NUM 10
using namespace std;

int n;
int ans[MAX_NUM];
int ch[MAX_NUM];

void print(){
    for(int i=0; i<n; i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
}

void dfs(int depth){
    if(depth == n){
        print();
        return;
    } else {
        for(int i=1; i<=n; i++){
            if(ch[i] == 0){
                ans[depth] = i;
                ch[i] = 1;
                dfs(depth+1);
                ch[i] = 0;
            }
        }
    }
}


int main(void) {
    
   
    cin >> n;
    
    for(int i=1; i<=n; i++){
        ans[0] = i;
        ch[i] = 1;
        dfs(1);
        ch[i] = 0;
    }
    
    return 0;
}
