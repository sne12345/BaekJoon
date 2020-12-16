#include <iostream>

using namespace std;

int pow(int n, int z)
{
	if (z == 1) return n;
	else return n * pow(n, z - 1);
}
int main()
{
	int a, p, d;
	int cnt = 0;
	int memo[10000000] = { 0 };
	int chk[10000000];
	int i = 0;

	cin >> a >> p;

	while (1) {
		chk[i++] = a;
		if (!memo[a]) {
			d = a;
			while (d != 0) {
				memo[a] += pow(d % 10, p);
				d /= 10;
			}
			cnt++;
		}
		else {
			int j;
			for (j = 0; j < i; j++) {
				if (chk[j] == chk[i - 1]) break;
			}
			cnt = j;
			break;
		}
		a = memo[a];
	}

	cout << cnt;

	return 0;
}
