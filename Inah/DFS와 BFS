#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> graph[10001];
int visited[10001];
queue<int> Q;

void DFS(int x)
{
	cout << x << " ";
	visited[x] = 1;

	for (int i = 0; i < graph[x].size(); i++) {
		int nx = graph[x][i];
		if (!visited[nx]) DFS(nx);
	}
}
void BFS(int x)
{
	Q.push(x);
	visited[x] = 1;

	while (!Q.empty()) {
		x = Q.front();
		cout << x << " ";
		Q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int nx = graph[x][i];
			if (!visited[nx]) {
				visited[nx] = 1;
				Q.push(nx);
			}
		}
	}
}
int main()
{
	int n, m, v;

	cin >> n >> m >> v;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 0; i < n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(v);
	cout << endl;
	memset(visited, 0, sizeof(visited));
	BFS(v);

	return 0;
}
