#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>  // memset

#define MAX_SIZE 101

using namespace std;

// 위, 오른, 아래, 왼
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n; // 행과 열의 수

int map[MAX_SIZE][MAX_SIZE]; // 지도
bool visited[MAX_SIZE][MAX_SIZE];

// BFS
void bfs(int x, int y, int depth){
  
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
                if(map[nx][ny] > depth && visited[nx][ny] == false){
                    visited[nx][ny]=true;

                    // 큐에 현재 nx,ny를 추가
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

int main (){
    int max = -1;
    int cnt[101] = {0};

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] > max)
                max = map[i][j];
        }
    }
    
    for(int d=0; d<=max; d++){
        // dis, visited 초기화
        memset(visited, false, sizeof(visited));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] > d && visited[i][j] == false){
                    cnt[d]++;
                    bfs(i, j, d);
                }
            }
        }
    }
    
    int cnt_max = -1;
    int cnt_max_id = -1;
    for(int i=0; i<=max; i++){
        if(cnt[i] > cnt_max){
            cnt_max_id = i;
            cnt_max = cnt[i];
        }
    }
    
    printf("%d\n",cnt[cnt_max_id]);
}
 
