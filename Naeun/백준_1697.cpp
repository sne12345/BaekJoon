#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>

#define MAX_SIZE 100001

using namespace std;

int n, m; // 수빈, 동생 위치

int dis[MAX_SIZE];
bool visited[MAX_SIZE]; // 방문했는지를 표시하는 지도

// BFS
void bfs(int x){
  
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
        nx = x * 2;
        
        // 지도를 벗어나지 않고
        if(nx <= MAX_SIZE-1 && visited[nx] == false){
            visited[nx]=true;

            // 해당 단지의 집의 수를 증가시킴
            dis[nx] = dis[x] + 1;
            
            if(nx == m){
                printf("%d\n", dis[nx]);
                return;
            }

            // 큐에 현재 nx를 추가
            q.push(nx);
        }
        
        // 해당 위치의 주변을 확인
        nx = x + 1;
        
        // 지도를 벗어나지 않고
        if(nx <= MAX_SIZE-1 && visited[nx] == false){
            visited[nx]=true;

            // 해당 단지의 집의 수를 증가시킴
            dis[nx] = dis[x] + 1;
            
            if(nx == m){
                printf("%d\n", dis[nx]);
                return;
            }

            // 큐에 현재 nx를 추가
            q.push(nx);
        }
        
        // 해당 위치의 주변을 확인
        nx = x - 1;
        
        // 지도를 벗어나지 않고
        if(0 <= nx && visited[nx] == false){
            visited[nx]=true;

            // 해당 단지의 집의 수를 증가시킴
            dis[nx] = dis[x] + 1;
            
            if(nx == m){
                printf("%d\n", dis[nx]);
                return;
            }

            // 큐에 현재 nx를 추가
            q.push(nx);
        
        }
    }
}

int main (){
    
    scanf("%d%d", &n, &m);
    
    if(n == m){
        printf("0\n");
    } else {
        dis[n] = 0;
        bfs(n);
    }
}
