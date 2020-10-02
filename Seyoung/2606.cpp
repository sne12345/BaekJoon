#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> map[101];
int ch[101];
int cnt = 0;
queue<int> Q;

int main() {
	freopen("input.txt", "rt", stdin);

	int v, e, a, b;
	int x;
	

	cin >> v; //컴퓨터 개수
	cin >> e; // 간선 수 

	// 1. 입력 받기
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a); //무방향, 양방향 인접리스트
	}

	ch[1] = 1;
	Q.push(1);

	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		cnt++;

		for (int i = 0; i < map[x].size(); i++) {
			if (ch[map[x][i]] == 0) {
				// 연결된 노드가 방문한 적 없는 노드일때
				ch[map[x][i]] = 1;
				Q.push(map[x][i]);
			}
		}
	}

	cout << cnt-1;

}
