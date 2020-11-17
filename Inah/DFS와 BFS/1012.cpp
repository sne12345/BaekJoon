#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[51][51];
int visited[51][51];
int m, n;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void DFS(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

		if(map[ny][nx] && !visited[ny][nx]) DFS(ny, nx);
	}
}
void print(int arr[][51])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int tc, k, x, y, cnt;
	
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		cin >> m >> n >> k;

		cnt = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] && !visited[i][j]) {
					cnt++;
					DFS(i, j);
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
