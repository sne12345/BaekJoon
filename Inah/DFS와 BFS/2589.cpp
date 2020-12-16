#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX 51
#define L 'L'
#define W 'W'

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n, m;
char map[MAX][MAX];
int chk[MAX][MAX] = { 0 };

void input()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}
int BFS(int x, int y)
{
	int minPath = 0;
	queue<pair<int, int>> Q;
	Q.push(make_pair(x, y));
	chk[x][y] = 1;

	while (!Q.empty()) {
		int cx = Q.front().first;
		int cy = Q.front().second;

		Q.pop();

		if (minPath < chk[cx][cy]) minPath = chk[cx][cy];

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (!chk[nx][ny] && map[nx][ny] == L) {
				Q.push(make_pair(nx, ny));
				chk[nx][ny] = chk[cx][cy] + 1;
			}
		}
	}

	return minPath - 1;
}
int main()
{
	cin >> n >> m;
	input();
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == L) {
				int r = BFS(i, j);
				answer = answer > r ? answer : r;
				memset(chk, 0, sizeof(chk));
			}
		}
	}
	cout << answer;
	return 0;
}
