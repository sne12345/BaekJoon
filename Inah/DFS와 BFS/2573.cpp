#include <iostream>
#include <cstring>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n, m;
int iceBerg[300][300] = { 0 };
int cntOcean[300][300] = { 0 };
int visited[300][300] = { 0 };

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> iceBerg[i][j];
		}
	}
}
void countOcean()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (iceBerg[i][j]) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

					if (!iceBerg[nx][ny]) cntOcean[i][j]++;
				}
			}
		}
	}
}
void DFS(int x, int y)
{
	visited[x][y] = 1;

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (iceBerg[nx][ny] && !visited[nx][ny]) DFS(nx, ny);
	}
}
int isSeparated()
{
	int cnt = 0;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (iceBerg[i][j] && !visited[i][j]) {
				cnt++;
				DFS(i, j);
			}
		}
	}
	return cnt;
}
void melt()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cntOcean[i][j]) {
				iceBerg[i][j] -= cntOcean[i][j];
				if (iceBerg[i][j] < 0) iceBerg[i][j] = 0;
			}
		}
	}
}
void print()
{
	cout << "iceBerg" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << iceBerg[i][j] << " ";
		}
		cout << endl;
	}
	cout << "cntOcean" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << cntOcean[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int sumCnt()
{
	int rslt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			rslt += cntOcean[i][j];
		}
	}
	return rslt;
}
int main()
{
	input();
	countOcean();

	//print();

	int year = 0;
	while (isSeparated() < 2) {
		if (sumCnt() == 0) {
			year = 0;
			break;
		}
		melt();
		memset(cntOcean, 0, sizeof(cntOcean));
		countOcean();
		//print();
		year++;
	}

	cout << year;

	return 0;
}
