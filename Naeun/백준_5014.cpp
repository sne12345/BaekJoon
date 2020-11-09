#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>

#define MAX_SIZE 10000001

using namespace std;

int f, s, g, u, d;

int dis[MAX_SIZE];
bool visited[MAX_SIZE]; // 방문했는지를 표시하는 배열

// BFS
void bfs(int x, int up, int down){
  
    queue <int> q; // 이용할 큐
    q.push(x);
    int nx;

    // 처음 x를 방문 했기때문에
    visited[x] = true;

    while(!q.empty()){

        // 큐의 현재 원소를 꺼내기
        x = q.front();
        q.pop();

        // 해당 위치의 주변을 확인
        nx = x + up;
        
        // 지도를 벗어나지 않고, 방문한 적 없으면
        if(nx >= 1 && nx <= f && visited[nx] == false){
            
            visited[nx]=true;

            // 해당 단지의 집의 수를 증가시킴
            dis[nx] = dis[x] + 1;
            
            if(nx == g){
                printf("%d\n", dis[nx]);
                return;
            }

            // 큐에 현재 nx를 추가
            q.push(nx);
        }
        
        // 해당 위치의 주변을 확인
        nx = x - down;
        
        // 지도를 벗어나지 않고, 방문한 적 없으면
        if(nx >= 1 && nx <= f && visited[nx] == false){
            
            visited[nx]=true;

            // 해당 단지의 집의 수를 증가시킴
            dis[nx] = dis[x] + 1;
            
            if(nx == g){
                printf("%d\n", dis[nx]);
                return;
            }

            // 큐에 현재 nx를 추가
            q.push(nx);
        }
    }
    printf("use the stairs\n");
}

int main (){
    
    scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
    
    if(s == g){
        printf("0\n");
    } else {
        bfs(s, u, d);
    }
    
}
