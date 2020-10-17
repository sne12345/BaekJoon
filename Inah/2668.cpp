#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> rslt;
vector<int> visited;

void DFS(int x, int y)
{
	if (visited[y]) {
		if (x == y) rslt.push_back(x);
	}
	else {
		visited[y] = 1;
		DFS(x, v[y]);
	}
}
int main()
{
	int n, a;

	cin >> n;

	v = vector<int>(n + 1, 0);
	visited = vector<int>(n + 1, 0);

	for(int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		DFS(i, i);
		visited = vector<int>(n + 1, 0);
	}

	cout << rslt.size() << endl;
	for (int i = 0; i < rslt.size(); i++) {
		cout << rslt[i] << endl;
	}
}