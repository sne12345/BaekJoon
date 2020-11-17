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
int num; // 직사각형의 개수
int a, b, c, d;
int dis_idx = 0;
int dis[MAX_SIZE];  // 분리된 각 영역의 넓이

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
                if(map[nx][ny] == 0 && visited[nx][ny] == false){
                    visited[nx][ny]=true;

                    // 해당 단지의 집의 수를 증가시킴
                    dis[dis_idx]++;

                    // 큐에 현재 nx,ny를 추가
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

void print_array(int arr[][MAX_SIZE]){
    printf("\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main (){

    scanf("%d%d%d", &n, &m, &num);

    for(int i = 0; i < num; i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        for(int x=b; x<d; x++){
            for(int y=a; y<c; y++){
                map[x][y] = 1;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0 && visited[i][j] == false){
                dis[dis_idx] = 1;
                bfs(i, j);
                dis_idx++;
                //print_array(map);
            }
        }
    }
    
    sort(dis, dis+dis_idx);
    
    printf("%d\n", dis_idx);
    for(int i=0; i<dis_idx; i++){
        printf("%d ",dis[i]);
    }
}
