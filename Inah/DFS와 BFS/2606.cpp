#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[100];
queue<int> q;
int chk[100];
int cnt = 0;

void BFS(int cv)
{
	q.push(cv);
	chk[cv] = 1;

	while (!q.empty()) {
		int nv = q.front();
		q.pop();

		for (int i = 0; i < v[nv].size(); i++) {
			int n = v[nv][i];
			if (!chk[n]) {
				chk[n] = 1;
				cnt++;
				q.push(n);
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	BFS(1);

	cout << cnt;

	return 0;
}
