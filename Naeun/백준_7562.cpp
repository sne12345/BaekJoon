#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>

#define MAX_SIZE 301

using namespace std;

// 위, 오른, 아래, 왼
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int num; // 총 테스트케이스 수
int n; // 행과 열의 수
int dis[MAX_SIZE][MAX_SIZE];
int caseNum = 0; // 테스트케이스 번호

struct piece {
    int x;
    int y;
};

struct piece knight[MAX_SIZE];
struct piece goal[MAX_SIZE];


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
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 지도를 벗어나지 않고
            if(0 <= nx && nx < n && 0 <= ny && ny < n){
                // 집이면서 방문하지 않았다면 -> 방문
                if(visited[nx][ny] == false){
                    visited[nx][ny]=true;

                    // 해당 단지의 집의 수를 증가시킴
                    dis[nx][ny] = dis[x][y] + 1;
                    
                    if(nx == goal[caseNum].x && ny == goal[caseNum].y){
                        printf("%d\n", dis[nx][ny]);
                        break;
                    }

                    // 큐에 현재 nx,ny를 추가
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

int main (){
    
    scanf("%d", &num);
    
    while(caseNum < num){
                
        // 초기화 : visited, dis
        memset(visited, false, sizeof(visited));
        memset(dis, 0, sizeof(dis));

        scanf("%d", &n);        // 체스판의 가로 세로
        
        scanf("%d%d", &knight[caseNum].x, &knight[caseNum].y);
        scanf("%d%d", &goal[caseNum].x, &goal[caseNum].y);
        
        if(knight[caseNum].x == goal[caseNum].x && knight[caseNum].y == goal[caseNum].y){
            printf("0\n");
            caseNum++;
            continue;
        }
        
        dis[knight[caseNum].x][knight[caseNum].y] = 0;
        bfs(knight[caseNum].x, knight[caseNum].y);
        
        caseNum++;
        
    }
}
