#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int MAX = 101;
int tomato[MAX][MAX][MAX];
int m, n, h, tmnum = 0, day = 0;
queue<pair<int, pair<int, int>>> tm;

struct Move {
	int x, y, z;
};
Move mv[6] = { {-1,0,0}, {1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1} };

bool finish(int i) {
	if (i == tmnum)
		return true;
	else
		return false;
}

int bfs() {
	int finishnum = tm.size();

	while (!tm.empty()) {
		int size = tm.size();

		for (int i = 0; i < size; i++) {
			int currenti = tm.front().first;
			int currentj = tm.front().second.first;
			int currentk = tm.front().second.second;
			tm.pop();

			for (int k = 0; k < 6; k++) {
				int movei = currenti + mv[k].x;
				int movej = currentj + mv[k].y;
				int movek = currentk + mv[k].z;

				if (movei >= 0 && movei < h && movej >= 0 && movej < n && movek >= 0 && movek < m) {
					if (tomato[movei][movej][movek] == 0) {
						finishnum++;
						tomato[movei][movej][movek] = 1;
						tm.push(make_pair(movei, make_pair(movej, movek)));
					}
				}
			}
		}
		day++;
		if (finish(finishnum))
			return day;
	}
	if (finish(finishnum))
		return day;
	return -1;
}

int main(void) {
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1)
					tm.push(make_pair(i, make_pair(j, k)));
				if (tomato[i][j][k] != -1)
					tmnum++;
			}
		}
	}
	if (tm.size() == tmnum) {
		cout << 0 << endl;
		return 0;
	}
	cout << bfs() << endl;
	return 0;
}
