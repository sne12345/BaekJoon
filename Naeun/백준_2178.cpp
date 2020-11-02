#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>

#define MAX_SIZE 101

using namespace std;

// 위, 오른, 아래, 왼
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m; // 행과 열의 수
int dis[MAX_SIZE][MAX_SIZE];

int map[MAX_SIZE][MAX_SIZE]; // 지도
bool visited[MAX_SIZE][MAX_SIZE]; // 방문했는지를 표시하는 지도


// BFS
void bfs(int x, int y){
  
    queue< pair<int,int> > q; // 이용할 큐, (x,y) -> (행, 열)
    q.push(make_pair(x,y)); // pair를 만들어서 queue에 넣습니다.

    // 처음 x,y를 방문 했기때문에
    visited[x][y] = true;

    while(!q.empty()){

        // 큐의 현재 원소를 꺼내기
        x = q.front().first;
        y = q.front().second;
        q.pop();

        // 해당 위치의 주변을 확인
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 지도를 벗어나지 않고
            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                // 집이면서 방문하지 않았다면 -> 방문
                if(map[nx][ny] == 1 && visited[nx][ny] == false){
                    visited[nx][ny]=true;

                    // 해당 단지의 집의 수를 증가시킴
                    dis[nx][ny] = dis[x][y] + 1;

                    // 큐에 현재 nx,ny를 추가
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

int main (){

    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            //입력을 1개씩 숫자로 끊어서 받습니다 -> %1d
            scanf("%1d", &map[i][j]);
    }
    
    dis[0][0] = 1;
    bfs(0, 0);

    printf("%d\n",dis[n-1][m-1]);
}
