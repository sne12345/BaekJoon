#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

#define MAX 301

using namespace std;

int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int l, minCnt, startX, startY, endX, endY;
int chk[MAX][MAX];
queue<pair<int, int>> Q;

void BFS()
{
	chk[startX][startY] = 1;
	Q.push(make_pair(startX, startY));

	while (!Q.empty()) {
		int cx = Q.front().first;
		int cy = Q.front().second;

		Q.pop();

		if (cx == endX && cy == endY) {
			minCnt = chk[cx][cy] < minCnt ? chk[cx][cy] : minCnt;
			continue;
		}

		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;

			if (!chk[nx][ny]) {
				chk[nx][ny] = chk[cx][cy] + 1;
				Q.push(make_pair(nx, ny));
			}
		}
	}
}
int main()
{
	int tc;

	cin >> tc;

	for (int t = 0; t < tc; t++) {
		minCnt = 9999;
		memset(chk, 0, sizeof(chk));
		cin >> l;
		cin >> startX >> startY >> endX >> endY;

		BFS();

		cout << minCnt - 1 << endl;
	}

	return 0;
}
