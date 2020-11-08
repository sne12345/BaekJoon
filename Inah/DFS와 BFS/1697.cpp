#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, k;
	int d[3] = { 1, -1, 2 };
	queue<int> Q;
	int chk[100000] = { 0 };

	int min = 9999;

	cin >> n >> k;

	if (n > k) min = n - k;
	else if (n == k) min = 0;
	else Q.push(n);

	chk[n] = 0;

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();

		if (x == k) min = chk[x] < min ? chk[x] : min;
		if (chk[x] > min) continue;

		for (int i = 0; i < 3; i++) {
			int nx;
			if (i == 2) nx = x * d[i];
			else nx = x + d[i];

			if (0 <= nx && nx <= 100000 && !chk[nx]) {
				chk[nx] = chk[x] + 1;
				Q.push(nx);
			}
		}
	}

	cout << min;

	return 0;
}
