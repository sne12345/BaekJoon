#include <stdio.h>
#include <iostream>
using namespace std;

int N, M;
int arr[10];

void dfs(int depth){
    if(depth == M){
        for(int i=0; i<M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    } else {
        for(int i=1; i<=N; i++){
            arr[depth] = i;
            dfs(depth+1);
        }
    }
}

int main(void) {
    
    cin >> N >> M;
    
    dfs(0);
    
    
    
    return 0;
}
