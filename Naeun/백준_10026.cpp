#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
#define MAX_SIZE 101

using namespace std;

// 위, 오른, 아래, 왼
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n; // 행과 열의 수

char map[MAX_SIZE][MAX_SIZE]; // 지도
bool visited[MAX_SIZE][MAX_SIZE]; // 방문했는지를 표시하는 지도

int cnt = 0, cntWeak = 0;


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
            if(0 <= nx && nx < n && 0 <= ny && ny < n){
                
                // 집이면서 방문하지 않았다면 -> 방문
                if(map[nx][ny] == map[x][y] && visited[nx][ny] == false){
                    visited[nx][ny]=true;

                    // 큐에 현재 nx,ny를 추가
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

void printVisited(bool visit[MAX_SIZE][MAX_SIZE]){
    printf("\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d", visited[i][j]);
        }
        printf("\n");
    }
}

void changeColor(char arr[][MAX_SIZE]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 'G')
                arr[i][j] = 'R';
        }
    }
}

int main (){
    
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%s", map[i]);
    }

    // 일반인
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == false){
                bfs(i, j);
                //printVisited(visited);
                cnt++;
            }
        }
    }
    
    // 초기화 및 G -> R
    memset(visited, false, sizeof(visited));
    changeColor(map);
    
    // 적록색약
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == false){
                bfs(i, j);
                //printVisited(visited);
                cntWeak++;
            }
        }
    }

    printf("%d %d\n",cnt, cntWeak);
}
