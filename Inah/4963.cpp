#include <stdio.h>
#include <cstring>

int map[50][50];
int chk[50][50];

int dx[8] = {-1, 1, 0, -1, 1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int w, h;

void DFS(int x, int y)
{
	int nx, ny;
	chk[x][y] = 1;
	
	for(int i = 0; i < 8; i ++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if(nx < 1 || nx > h || ny < 1 || ny > w) continue;
		if(!chk[nx][ny] && map[nx][ny]) {
			DFS(nx, ny);
		}
	}
}
int main()
{
	int cnt;
	
	while(1) {
		scanf("%d %d", &w, &h);
		
		if(w == 0 && h == 0) break;
		
		for(int i = 1; i <= h; i++) {
			for(int j = 1; j <= w; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		
		cnt = 0;

		for(int i = 1; i <= h; i++) {
			for(int j = 1; j <= w; j++) {
				if(!chk[i][j] && map[i][j]) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		
		printf("%d\n", cnt);
		
		memset(chk, 0, sizeof(chk));
		memset(map, 0, sizeof(map));
	}
}
