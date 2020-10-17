#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char sq[27][27];
int visited[26][26] = { 0 };
int n;
int area = 1; 

int direct[4][2] = {
	-1, 0,
	1, 0,
	0, -1,
	0, 1
};

void findHouse(int y, int x) {

	
	visited[y][x] = 1;
	area = area + 1;

	int dy, dx;

	for (int i = 0; i < 4; i++) {
		dy = y + direct[i][0];
		dx = x + direct[i][1];

		if ((dy >= 0 && dy < n) && (dx >= 0 && dx < n)) {
			if (visited[dy][dx] == 0 && sq[dy][dx] == '1') {
				findHouse(dy, dx);
			}
		}
	}
}

int main() {
	int cnt = 0;
	int index = -1;
	vector<int> size;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> sq[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]==0 && sq[i][j] == '1') {
				area = 0;
				index++;
				findHouse(i, j);
				size.push_back(area);
				cnt++;
			}
		}
	}

	cout << cnt<<endl;

	sort(size.begin(), size.end());

	for (int i = 0; i < cnt; i++) {
		cout << size[i] << endl;
	}

}
