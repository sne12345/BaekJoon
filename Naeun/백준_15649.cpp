#include <stdio.h>
#include <iostream>
using namespace std;

int N, M;
int arr[9];
int ch[9];

void dfs(int depth){
    if(depth == M){
        for(int i=0; i<M; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    } else {
        for(int i=1; i<=N; i++){
            if(ch[i] == 0){
                ch[i] = 1;
                arr[depth] = i;
                dfs(depth + 1);
                ch[i] = 0;
            }
        }
    }
}

int main(void) {
    
    cin >> N >> M;
    
    dfs(0);
    
    return 0;
}
