#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>
using namespace std;
int sq[101][101];
int visited[101][101];
int n, m;

int direct[4][2] = {
	-1, 0,
	1, 0,
	0, -1,
	0, 1
};

void bfs(int i, int j) {
	int dy, dx;

	queue<pair<int, int> > q;
	q.push(make_pair(j, i));
	visited[j][i] = 1;

	while (!q.empty()) {

		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			dy = y + direct[i][0];
			dx = x + direct[i][1];
			

			if ((dy >= 0 && dy < n) && (dx >= 0 && dx < m)) {
				if (visited[dy][dx] == 0 && sq[dy][dx] == 1) {
					q.push(make_pair(dy, dx));
					visited[dy][dx] = visited[y][x] + 1; // 길이 계속 더하는 거임
				}
				else if (visited[dy][dx] == 0)
					visited[dy][dx] = -1;
			}
		}
	}
	
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &sq[i][j]);
		}
	}
	visited[0][0] = 1;
	bfs(0, 0);

	cout << visited[n - 1][m - 1];
}
