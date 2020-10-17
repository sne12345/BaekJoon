#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int set[101];
bool visited[101];
bool cycle[101];
int cnt = 0;
int n;

bool dfs(int start, int setIndex) {

	if (visited[setIndex] == 1) return false; //방문한 적 있으면 사이클 X

	visited[setIndex] = true;

	if (start == setIndex || dfs(start, set[setIndex])) {
		cnt++;
		cycle[setIndex] = true;
		return true;
	}

	return false;
}

int main() {

	vector<int> v;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> set[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[j] = cycle[j];
		}
		dfs(i, set[i]);
	}

	cout << cnt << endl;

	for (int i = 1; i <= n; i++)
		if (cycle[i])
			cout << i << endl;
	cout << endl;

	return 0;

}
