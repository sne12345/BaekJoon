#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

vector<vector<int>> map; 
vector<vector<int>> around; 
vector<vector<int>> visited;

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		if (map[ny][nx] && !visited[ny][nx]) {
			visited[ny][nx] = 1;
			dfs(ny, nx);
		}
	}
	return;
}

int main() {

	cin >> N >> M;

	map = vector<vector<int>>(N, vector<int>(M, 0));
	around = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<int>>(N, vector<int>(M, 0));

	queue<pair<int, int>> q; 

	// 먼저 다 담을 생각을 했어야 했는데
	// bfs탐색을 하며 하나씩 담는대로 코드를 짜서 망했다
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j])
				q.push(make_pair(i, j));
		}

	int ans = 0; //시간
	bool check = false; 
	while (!q.empty()) {

		ans++; //시간
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;

				//주위에 바다 있는지
				if (map[ny][nx] == 0)
					around[y][x]++;
			}
		}

		//빙산 높이 업데이트
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				map[i][j] = (map[i][j] - around[i][j] >= 0) ? map[i][j] - around[i][j] : 0;
				if (map[i][j])
					q.push(make_pair(i, j));
			}

		// bfs로 녹이고, dfs 로 다시 탐색하려니 너무 오래걸리는거같아 보니
		// 그 방법이 맞았다..
		int cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (map[i][j] && !visited[i][j]) {
					visited[i][j] = 1;
					cnt++;
					dfs(i, j);
				}
			}

		if (cnt > 1) {
			check = true;
			break;
		}

		visited = vector<vector<int>>(N, vector<int>(M, 0));
		around = vector<vector<int>>(N, vector<int>(M, 0));

	}

	if (check == false)
		ans = 0;

	cout << ans << endl;
	return 0;
}

