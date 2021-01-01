#include <stdio.h>
#include <iostream>
using namespace std;

int N, M;
int arr[10];


void dfs(int s, int depth){
    if(depth == M){
        for(int i=0; i<M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    } else {
        for(int i=s; i<=N; i++){
            arr[depth] = i;
            dfs(i, depth+1);
        }
    }
}

int main(void) {
    
    cin >> N >> M;
    
    dfs(1, 0);
    
    
    return 0;
}
