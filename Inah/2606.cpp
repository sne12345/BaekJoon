#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	int x, y;
	
	vector<int> map[101];
	int visited[101] = {0};
	queue<int> Q;
	
	int cnt = 0;
	
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++) {
       scanf("%d %d", &x, &y);
	   map[x].push_back(y);
	   map[y].push_back(x);
	}
	
	Q.push(1);
	visited[1] = 1;
	
	while(!Q.empty()) {
		x = Q.front();
		Q.pop();
		cnt++;
		for(int i = 0; i < map[x].size(); i++) {
			if(!visited[map[x][i]]) {
				visited[map[x][i]] = 1;
				Q.push(map[x][i]);
			}
		}
	}
	
	cnt -= 1;
	
	printf("%d", cnt);
}
