#include <cstdio>
using namespace std;

int n, m, cnt = 0;
int map[50][50];

int nexty[4] = { -1, 0, 1, 0 };
int nextx[4] = { 0, 1, 0, -1 };

int backy[4] = { 1, 0, -1, 0 };
int backx[4] = { 0, -1, 0, 1 };

void dfs(int y, int x, int d) {
	int k;

	if (map[y][x] == 0) {
		cnt++;
		map[y][x] = 2;
	}

	// 현재방향을 기준으로 왼쪽이라는 말을 이해를 못했는데
	// 0입력받은 북쪽이면 실상 서쪽부터 탐색임 서쪽은 3
	// 방향 설정만 빼면 전형적인 dfs문제
	for (k = d - 1; k > d - 5; k--) {

		int newk = (k + 4) % 4;
		int newy = y + nexty[newk];
		int newx = x + nextx[newk];

		if (newy < 0 || newy > n - 1 || newx < 0 || newx > m - 1) continue;

		if (map[newy][newx] == 0) {
			dfs(newy, newx, newk);
			return;
		}
	}

	if (map[y + backy[d]][x + backx[d]] == 1) return;
	else dfs(y + backy[d], x + backx[d], d);
}

int main() {

	int r, c, d, i, j;

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs(r, c, d);

	printf("%d\n", cnt);

	return 0;
}
