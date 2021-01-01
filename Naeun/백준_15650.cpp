#include <stdio.h>
#include <iostream>
using namespace std;

int N, M;
int ch[9];
int arr[9];

void dfs(int s, int depth){
    if(depth == M){
        for(int i=0; i<M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    } else {
        for(int i=s; i<=N; i++){
            if(ch[i] == 0){
                ch[i] = 1;
                arr[depth] = i;
                dfs(i, depth+1);
                ch[i] = 0;
            }
        }
    }
}

int main(void) {
    
    cin >> N >> M;
    
    dfs(1, 0);
    
    
    return 0;
}
