#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#define MAX_SIZE 301
using namespace std;

int n, m;
int cnt = 0, year = 0;   // 덩어리 수, 지난 년도
int map[MAX_SIZE][MAX_SIZE];

int map2[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(int x, int y){
    queue< pair<int, int> > q;
    q.push(make_pair(x, y));
    
    visited[x][y] = true;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(map2[nx][ny] > 0 && visited[nx][ny] == false){
                    
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
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

int main(void) {
    
    scanf("%d%d", &n, &m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
        }
    }
    
    memcpy(map2, map, sizeof(map));
    
    // 덩어리 개수 세기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map2[i][j] > 0 && visited[i][j] == false){

                BFS(i, j);
                cnt++;
            }
        }
    }
    
    // 처음부터 2 이상인지, 0인지 확인
    if(cnt >= 2 || cnt == 0){
        printf("0\n");
        return 0;
    }

    
    while(cnt < 2){
        cnt = 0;
        memset(visited, false, sizeof(visited));
        
        int mx, my;
        // 1 이상인 숫자 주위 체크해서 1 감소시키기
        for(int i=0; i<(n); i++){
            for(int j=0; j<(m); j++){
                if(map[i][j] > 0){
                    for(int k=0; k<4; k++){
                        mx = i + dx[k];
                        my = j + dy[k];

                        if(mx >= 0 && mx <n && my >= 0 && my < m){
                            if(map[mx][my] == 0 && map2[i][j] > 0){
                                map2[i][j]--;
                            }
                        }
                    }
                }
            }
        }

        // 덩어리 개수 세기
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map2[i][j] > 0 && visited[i][j] == false){

                    BFS(i, j);
                    cnt++;
                }
            }
        }
        
//        print_array(map);
//        print_array(map2);
        
        if(cnt == 0){
            printf("0\n");
            return 0;
        }
        
        year++;
        
        memcpy(map, map2, sizeof(map2));
    }
    
    printf("%d\n", year);
    

    return 0;
}
