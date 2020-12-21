#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX 10001

using namespace std;

int n, m;
vector<int> com[MAX];
int chk[MAX];
int virus[MAX];
vector<int> rslt;
int maxNum = -999;

void DFS(int v, int x)
{
	chk[x] = 1;

	for (int i = 0; i < com[x].size(); i++) {
		int nx = com[x][i];
		if (!chk[nx]) {
			virus[v]++;
			DFS(v, nx);
		}
	}
}
int main()
{
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> b >> a;
		com[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		memset(chk, 0, sizeof(chk));
		DFS(i, i);
		maxNum = virus[i] > maxNum ? virus[i] : maxNum;
	}

	for (int i = 1; i <= n; i++) {
		if (virus[i] == maxNum) rslt.push_back(i);
	}
	
	sort(rslt.begin(), rslt.end());

	for(int i = 0; i < rslt.size(); i++) {
		cout << rslt[i] << " ";
	}
	
	return 0;
}
