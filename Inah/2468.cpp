#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;

int map[101][101];
int chk[101][101];
int n, m;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int cnt = 0;

priority_queue<int> q;

void BFS(int limit, int x, int y)
{
   chk[x][y] = 1;
   queue<pair<int, int> > pq;
   pq.push(make_pair(x, y));
   while(!pq.empty()) {
      int nx = pq.front().first;
      int ny = pq.front().second;
      
      pq.pop();
      
      for(int i = 0; i < 4; i ++) {
         int newX = nx + dx[i];
         int newY = ny + dy[i];
         if(newY > n || newY == 0 || newX > n || newX <= 0) continue;
         if(chk[newX][newY]) continue;
         if(map[newX][newY] > limit) {
            chk[newX][newY] = 1;
            pq.push(make_pair(newX, newY));
         }
      }
   }
}

int main()
{
   scanf("%d", &n);
   for(int i = 1; i <= n; i++) {
      for(int j = 1 ; j <= n; j++) {
         scanf("%d", &map[i][j]);
         m = max(map[i][j], m);
      }
   }
   
   for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
         for(int k = 1; k <= n; k++) {
            if(!chk[j][k] && map[j][k] > i) {
               BFS(i, j, k);
               cnt++;
            }
         }
      }
      q.push(cnt);
      memset(chk,0,sizeof(chk));
        cnt = 0;
   }
   q.push(1);
   printf("%d\n", q.top());
}
