#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

char map[502][502];
int ch[501];
int r, c;

int main() {
	freopen("input.txt", "rt", stdin);
	queue<pair<int, int> > wlist;

	cin >> r >> c;
	// 방향이 있는 리스트
	
	// 1. 입력받기 
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];

			// 늑대면 늑대 리스트에 넣기
			if (map[i][j] == 'W') {
				wlist.push({ i, j });
			}
		}
	}

	// 울타리 개수에 제한이 없다
	// 최대한 모든 경로를 차단하면 된다..

	while (!wlist.empty()) {
		int y = wlist.front().first;
		int x = wlist.front().second;
		wlist.pop();

		for (int i = 0; i < 4; i++) {
			int newy = y + dy[i];
			int newx = x + dx[i];

			// 범위 안에 있어야함
			if (newy > 0 && newy <= r && newx > 0 && newx <= c)
			{
				if (map[newy][newx] == '.')
				{
					map[newy][newx] = 'D';
				}
				else if (map[newy][newx] == 'S') // 양을 만나면
				{
					cout << 0 << endl;
					return 0;
				}
			}
		}
	}

	cout << 1 << endl;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	
}
