#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, start;
int a, b, x;

int map_D[1001][1001], cnt = 0;
int ch_D[1001];

vector<int> map_B[1001];
queue<int> Q;
int ch_B[1001];        // ch는 방문했는지 안했는지

void DFS(int v){            // v -> 정점 번호
    printf("%d ", v);
    
    if(cnt == n) {
        return;
    }
    for(int i=1; i<=n; i++){
        if(map_D[v][i] == 1 && ch_D[i] == 0){
            cnt++;
            ch_D[i] = 1;                          // 한 번 길 갈 때, 똑같은 곳을 또 방문하지 않기 위해
            DFS(i);
        }
    }
}

int main(void) {
    
    scanf("%d%d%d", &n, &m, &start);
    
    for(int i=1; i<=m; i++){
        scanf("%d%d", &a, &b);
        map_D[a][b] = 1;
        map_D[b][a] = 1;
        map_B[a].push_back(b);
        map_B[b].push_back(a);
    }
    
    // DFS
    ch_D[start] = 1;
    cnt++;
    DFS(start);
    printf("\n");
    
    
    // BFS
    // 작은 수부터 조건이 있으니까 정렬해주기
    for(int i=1; i<=n; i++){
        sort(map_B[i].begin(), map_B[i].end());
    }
    
    Q.push(start);
    ch_B[start] = 1;
    
    while(!Q.empty()){
        printf("%d ", Q.front());
        x = Q.front();
        Q.pop();
        
        for(int i=0; i<map_B[x].size(); i++){
            
            if(ch_B[map_B[x][i]] == 0){
                ch_B[map_B[x][i]] = 1;
                Q.push(map_B[x][i]);
            }
        }
    }
    return 0;
}
