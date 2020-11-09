#include <iostream>
#include <cstring>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n;
int ground[101][101];
int chk[101][101];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ground[i][j];
		}
	}
}
void DFS(int x, int y, int r)
{
	chk[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

		if (!chk[nx][ny] && ground[nx][ny] > r) DFS(nx, ny, r);
	}
}
int main()
{
	input();

	int safe, max = -9999;
	int maxValue = -999;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maxValue = ground[i][j] > maxValue ? ground[i][j] : maxValue;
		}
	}

	for (int r = 0; r <= maxValue; r++) {
		safe = 0;
		memset(chk, 0, sizeof(chk));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!chk[i][j] && ground[i][j] > r) {
					safe++;
					DFS(i, j, r);
				}
			}
		}
		max = safe > max ? safe : max;
	}

	cout << max;

	return 0;
}
