#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int N;

int startx, starty;
int endx, endy;

vector<pair<int, int>> cs;

bool bfs(int x, int y) {

	vector<bool> visited;

	// 편의점 개수만큼 사이즈 만들고 false로 초기화
	visited = vector<bool>(N + 2, false);

	visited[0] = true;

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int here_x = q.front().first;
		int here_y = q.front().second;
		q.pop();

		for (int i = 1; i < N + 2; ++i) {
			int there_x = cs[i].first;
			int there_y = cs[i].second;

			if (visited[i] == false && (abs(there_x - here_x) + abs(there_y - here_y) <= 1000)) {
				q.push(make_pair(there_x, there_y));
				visited[i] = true;
			}
		}
	}
	return visited[N + 1];
}


int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &N);
		scanf("%d %d", &startx, &starty);

		cs.clear();
		// 집 위치 넣기
		cs.push_back(make_pair(startx, starty));
		// 편의점 넣기
		for (int i = 0; i < N; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			cs.push_back(make_pair(x, y));
		}
		// 도착지 넣기
		scanf("%d %d", &endx, &endy);
		cs.push_back(make_pair(endx, endy));


		bool res = bfs(startx, starty);

		if (res) {
			printf("happy\n");
		}
		else {
			printf("sad\n");
		}
	}
}
