#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

int n, m;
char graph[MAX][MAX] = { 0 };
int chk[MAX][MAX] = { 0 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int> > q;

void BFS()
{
	q.push(pair<int, int>(0, 0));
	chk[0][0] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
				continue;
			}

			if (graph[ny][nx] == '1') {
				if (!chk[ny][nx]) {
					chk[ny][nx] = chk[cy][cx] + 1;
					q.push(pair<int, int>(nx, ny));
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> graph[i];
	}

	BFS();
	cout << chk[n - 1][m - 1] << endl;
}
