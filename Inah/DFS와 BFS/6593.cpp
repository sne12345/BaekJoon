#include <iostream>
#include <cstring>
#include <queue>

#define MAX 30

using namespace std;

int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int df[] = { 0, 0, 0, 0, 1, -1 };

int L, R, C;
char build[MAX][MAX][MAX];
int chk[MAX][MAX][MAX];
pair<pair<int, int>, int> Start, End;

void input()
{
	for (int l = 0; l < L; l++) {
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				cin >> build[l][r][c];
				if (build[l][r][c] == 'S') {
					Start.first.first = l;
					Start.first.second = r;
					Start.second = c;
				}
				if (build[l][r][c] == 'E') {
					End.first.first = l;
					End.first.second = r;
					End.second = c;
				}
			}
		}
	}
}
int BFS(int a, int b, int c)
{
	queue<pair<pair<int, int>, pair<int, int>>> Q;
	Q.push(make_pair(make_pair(a, b), make_pair(c, 0)));
	chk[a][b][c] = 1;

	while (!Q.empty()) {
		int f = Q.front().first.first;
		int x = Q.front().first.second;
		int y = Q.front().second.first;
		int cnt = Q.front().second.second;
		Q.pop();

		if (f == End.first.first && x == End.first.second && y == End.second) return cnt;

		for (int i = 0; i < 6; i++) {
			int nf = f + df[i];
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nf < 0 || nf >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

			if (build[nf][nx][ny] == '#') continue;

			if (build[nf][nx][ny] == '.' || build[nf][nx][ny] == 'E') {
				if (!chk[nf][nx][ny]) {
					chk[nf][nx][ny] = 1;
					Q.push(make_pair(make_pair(nf, nx), make_pair(ny, cnt + 1)));
				}
			}
		}
	}

	return -1;
}
int main()
{
	while (1) {
		cin >> L >> R >> C;

		if (L == 0 || R == 0 || C == 0) break;

		memset(chk, 0, sizeof(chk));
		input();

		int rslt = BFS(Start.first.first, Start.first.second, Start.second);

		if (rslt == -1) {
			cout << "Trapped!" << endl;
		}
		else {
			cout << "Escaped in " << rslt << " minute(s)." << endl;
		}
	}

	return 0;
}
