
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int W[11][11];
int visited[11];

int N;
int start;
long long int m = 98765432;

void printArr(int arr[11][11]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


void dfs(int start, int n, int cost, int cnt){
    
    // 선택한 노드의 수가 총 개수이고, 시작 노드까지의 경로가 있으면
    if(cnt == (N-1) && W[n][start] != 0){
        cost += W[n][start];
        if(cost < m)
            m = cost;
        return;
    } else {
        for(int i=0; i<N; i++){
            
            if(n == i || W[n][i] == 0)
                continue;
            
            // 간 적이 없는 노드일 때
            if(visited[i] == 0){
                
                visited[i] = 1;
                dfs(start, i, cost + W[n][i], cnt+1);
                visited[i] = 0;
            }
        }
    }
}


int main(void) {

    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &W[i][j]);
        }
    }

    // 0에서 출발하는 것만 구해도 됨 -> 싸이클이 있기 때문에 다른 출발점으로 해도 동일함
    visited[0] = 1;
    dfs(0, 0, 0, 0);
    
    printf("%lld\n", m);
    
    return 0;
}
