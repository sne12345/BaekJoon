#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n;
char map[30][30];
int visited[30][30] = { 0 };

int cnt = 0;
int subCnt;
vector<int> rslt;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
queue<pair<int, int> > Q;

void BFS(int x, int y)
{
	Q.push(make_pair(x, y));
	visited[x][y] = 1;
	cnt++;

	while (!Q.empty()) {
		int cx = Q.front().first;
		int cy = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			if (visited[nx][ny] == 0 && map[nx][ny] == '1') {
				cnt++;
				visited[nx][ny] = 1;
				Q.push(make_pair(nx, ny));
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && map[i][j] == '1') {
				cnt = 0;
				BFS(i, j);
				rslt.push_back(cnt);
			}
		}
	}

	sort(rslt.begin(), rslt.end());

	cout << rslt.size() << endl;
	for (int i = 0; i < rslt.size(); i++) {
		cout << rslt[i] << endl;
	}
}