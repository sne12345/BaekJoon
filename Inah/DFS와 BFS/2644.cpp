#include <iostream>
#include <vector>

using namespace std;

vector<int> rel[100];
int chk[100] = { 0 };

void DFS(int s, int e, int cnt)
{
	chk[s] = ++cnt;

	if (s == e) return;

	for (int i = 0; i < rel[s].size(); i++) {
		int ns = rel[s][i];
		if (!chk[ns]) DFS(ns, e, cnt);
	}
}
int main()
{
	int n, m, p1, p2, x, y;

	cin >> n;
	cin >> p1 >> p2;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		rel[x].push_back(y);
		rel[y].push_back(x);
		if (x == y) {
			cout << 0;
			return 0;
		}
	}

	DFS(p1, p2, 0);

	cout << chk[p2] - 1;

	return 0;
}
