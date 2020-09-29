#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <string.h>
#include <stdio.h>
using namespace std;

int N,M = -1;
int depth[101][101];
int visited[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int cnt = 0;

queue < int > pq;

void bfs(int limit, int y, int x) {
    visited[y][x] = 1;
    queue < pair < int,int > > q;
    q.push(make_pair(y,x));
    while(!q.empty()) {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int newy = ny + dy[i];
            int newx = nx + dx[i];
            if(newy > N || newy <= 0 || newx > N || newx <= 0)
                continue;
            if(visited[newy][newx])
                continue;
            if(depth[newy][newx] > limit) {
                visited[newy][newx] = 1;
                q.push(make_pair(newy,newx));
            }
        }
    }
}

int main() {
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&depth[i][j]);
            M = max(depth[i][j],M);
        }
    }
    for(int i=1; i<M; i++) {
        for(int j=1; j<=N; j++) {
            for(int k=1; k<=N; k++) {
                if(visited[j][k] == 0 && depth[j][k] > i) {
                    bfs(i,j,k);
                    cnt++;
                }
            }
        }
        pq.push(cnt);
        memset(visited,0,sizeof(visited));
        cnt = 0;
    }
    pq.push(1);
    printf("%d\n",pq.top());
}
