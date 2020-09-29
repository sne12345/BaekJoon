#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue> 
#include <algorithm>
using namespace std;

int N;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int visit[101][101];
int map[101][101];
queue<pair<int, int> >q;

void bfs(int x,int y,int hei){
    q.push(make_pair(x,y));
    visit[x][y] = 1; // 방문 체크  
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        // 해당 점을 큐에 넣고 
        q.pop();
        // 빼면서 
		
		// 해당 점과 인접한 점들 찾아 나서기  
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 위 아래 왼쪽 오른쪽이어야 하고  
            if(nx>0 && nx<=N && ny>0 && ny<=N){
            	// 제시된 높이보다 커야되고,방문한 적도 없는 점일 경우에만  
                if(map[nx][ny]>hei && visit[nx][ny] == 0){
                	// 방문 표시하고  
                	visit[nx][ny] = 1;
                    // 해당 점을 또 넣는다 
					q.push(make_pair(nx,ny));
                }
            }
        }
    }
}



int main(void){
	freopen("input.txt", "rt", stdin);
	int height = 0;
    int count = 0;
    int max_c = 0;
	scanf("%d", &N);
	
	int min_height=100,max_height=1;
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &map[i][j]);
			if(height<=map[i][j])
				height=map[i][j];
		}
	}
	
	// 가장 큰 높이 구함  
	
	// 0부터 높이 만큼 반복하면서 최대 연결개수 구하기  
	for(int h=0;h<=height;h++){
        count = 0;
        // 매번 포문 돌때마다 방문 배열 초기화  
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                visit[i][j] = 0;

        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
            	// 방문한 적 없고 특정 높이보다 클 경우  
                if(map[i][j]>h && visit[i][j] == 0){
                    count++;
                    bfs(i,j,h); // 해당 점과 높이에 대해 BFS 탐색 시작  
                }
        if(max_c <= count)
            max_c = count;
    }
    printf("%d", max_c);

}


