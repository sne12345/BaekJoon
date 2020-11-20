#include <iostream>
#include <vector>
#include <cstring>

#define MAX 101

using namespace std;

int n, m;
vector<int> rel[MAX];
int bacon[MAX] = { 0 };
int chk[MAX] = { 99999 };
int subMin;

void print(int arr[])
{
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void DFS(int from, int s, int to, int cnt)
{
	if (s == to) {
		subMin = cnt < subMin ? cnt : subMin;
		return;
	}
	chk[s] = 1;

	//cout << "chk" << endl;
	//print(chk);

	for (int i = 0; i < rel[s].size(); i++) {
		if (!chk[rel[s][i]]) {
			DFS(from, rel[s][i], to, cnt + 1);
		}
	}
}
int main()
{
	cin >> n >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		rel[x].push_back(y);
		rel[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j != i) {
				subMin = 9990;
				memset(chk, 0, sizeof(chk));
				//cout << "i : " << i << ", j : " << j << endl;
				DFS(i, i, j, 0);
				bacon[i] += subMin;
				//cout << "subMin : " << subMin << endl;
				//cout << "bacon" << endl;
				//print(bacon);
			}
		}
	}

	int minIdx = 1;
	for (int i = 1; i <= n; i++) {
		minIdx = bacon[i] < bacon[minIdx] ? i : minIdx;
	}
	cout << minIdx;

	return 0;
}
