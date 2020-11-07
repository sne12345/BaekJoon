#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int box[100][100][50];
queue<pair<pair<int, int>, int>> Q;

int m, n, h;

void print()
{
	cout << "box" << endl;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << box[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
}
void BFS()
{
	while (!Q.empty()) {
		int cx = Q.front().first.first;
		int cy = Q.front().first.second;
		int cz = Q.front().second;
		Q.pop();

		int i;
		for (i = 0; i < 6; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nz = cz + dz[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;

			if (box[nx][ny][nz] == 0) {
				box[nx][ny][nz] = box[cx][cy][cz] + 1;
				Q.push(make_pair(make_pair(nx, ny), nz));
			}
		}
	}
}
int main()
{
	cin >> m >> n >> h;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) Q.push(make_pair(make_pair(i, j), k));
			}
		}
	}

	if (Q.empty()) {
		cout << "-1" << endl;
		return 0;
	}

	BFS();

	int max = -1000;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!box[i][j][k]) {
					cout << "-1" << endl;
					return 0;
				}
				max = box[i][j][k] > max ? box[i][j][k] : max;
			}
		}
	}

	cout << max - 1;

	return 0;
}
