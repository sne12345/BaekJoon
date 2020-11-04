#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int map[1001][1001];
int N, M, V;
int visit[1001];


void dfs(int now) {

	cout << now << ' ';
	for (int i = 1; i <= N; i++) {
		if (map[now][i] == 1 && visit[i] == 0) {
			visit[i] = 1;
			dfs(i);
		}
	}
}
int main() {


	cin >> N >> M >> V;
	int a, b;

	// 간선 입력
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	visit[V] = 1;
	dfs(V);
	cout << endl;
	memset(visit, 0, sizeof(visit));

	queue<int> q;
	int cur;

	q.push(V);
	visit[V] = 1;

	while (!q.empty()) {

		cur = q.front();
		q.pop();
		cout << cur<<' ';

		for (int i = 1; i <= N; i++) {
			if (map[cur][i] == 1 && visit[i] == 0) {
				visit[i] = 1;
				q.push(i);
			}
		}
	}

}
