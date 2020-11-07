#include <iostream>
#include <queue>
using namespace std;

int n; // 전체 사람 수
int a, b; // b가 찾으려는 관계의 사람
int rel;

int map[101][101];
int dst[101];
queue<int> q;

int main() {
	
	int x, y;
	int cnt = 0;

	cin >> n;
	cin >> a >> b;
	cin >> rel;

	// 부모관계 모두 입력
	for (int i = 0; i < rel; i++) {
		cin >> x >> y;
		map[x][y]= map[y][x] = 1;
	}
	q.push(a);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (dst[i] == 0 && map[cur][i] == 1) {
				dst[i] = dst[cur] + 1;
				q.push(i);
			}
		}
	}
	if (dst[b] == 0) cout << -1;
	else cout << dst[b];

	
}
