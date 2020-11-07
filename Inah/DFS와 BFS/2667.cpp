#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

char apt[25][25];
int chk[25][25];
vector<int> complex;
queue<pair<int, int> > q;
int cnt;
int n;

void BFS(int x, int y)
{
	q.push(make_pair(x, y));
	chk[x][y] = 1;
	cnt++;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			if (!chk[nx][ny] && apt[nx][ny] == '1') {
				q.push(make_pair(nx, ny));
				chk[nx][ny] = 1;
				cnt++;
			}
		}
	}
}
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> apt[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!chk[i][j] && apt[i][j] == '1') {
				cnt = 0;
				BFS(i, j);
				complex.push_back(cnt);
			}
		}
	}

	sort(complex.begin(), complex.end());

	cout << complex.size() << endl;
	for (int i = 0; i < complex.size(); i++) {
		cout << complex[i] << endl;
	}

	return 0;
}
