#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

vector<int> rslt;
int m, n, k;
int cnt;
int graph[101][101] = { 0 };
int visited[101][101] = { 0 };

void DFS(int x, int y)
{
	cnt++;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (!graph[nx][ny] && !visited[nx][ny]) DFS(nx, ny);
	}
}
void print(int arr[][101])
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
	cin >> n >> m >> k;
	
	int x1, x2, y1, y2;
	for (int i = 0; i < k; i++) {
		cin >> y1 >> x1 >> y2 >> x2;

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				graph[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!graph[i][j] && !visited[i][j]) {
				cnt = 0;
				DFS(i, j);
				rslt.push_back(cnt);
			}
		}
	}

	sort(rslt.begin(), rslt.end());

	cout << rslt.size() << endl;
	for (int i = 0; i < rslt.size(); i++) {
		cout << rslt[i] << " ";
	}
	return 0;
}
