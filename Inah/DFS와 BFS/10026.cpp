#include <iostream>
#include <cstring>

#define MAX 101

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n;
char pic[MAX][MAX];
int chk[MAX][MAX];

void DFS(int x, int y, char c, bool isDis)
{
	chk[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

		if (!isDis) {
			if(!chk[nx][ny] && pic[nx][ny] == c) DFS(nx, ny, c, isDis);
		}
		else {
			if (!chk[nx][ny]) {
				if (c == 'R' || c == 'G') {
					if(pic[nx][ny] == 'R' || pic[nx][ny] == 'G') DFS(nx, ny, c, isDis);
				}
				else {
					if (pic[nx][ny] == c) DFS(nx, ny, c, isDis);
				}
			}
		}
	}
}
int main()
{
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> pic[i][j];
		}
	}

	//아닌 사람이 봤을 때
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!chk[i][j]) {
				cnt++;
				DFS(i, j, pic[i][j], 0);
			}
		}
	}
	cout << cnt << " ";

	//초기화 작업
	memset(chk, 0, sizeof(chk));
	cnt = 0;
	
	//적록색 약인 사람이 봤을 때
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!chk[i][j]) {
				cnt++;
				DFS(i, j, pic[i][j], 1);
			}
		}
	}
	cout << cnt;

	return 0;
}
