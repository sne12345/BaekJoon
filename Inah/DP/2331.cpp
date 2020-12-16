#include <iostream>

using namespace std;

int pow(int n, int z)
{
	if (z == 1) return n;
	else return n * pow(n, z - 1);
}
int main()
{
	int a, p, d = 0;
	int cnt = 0;
	int chk[10000000] = { 0 };

	cin >> a >> p;

	while (1) {
		if (chk[a] == 0) {
			d = 0;
			chk[a] = ++cnt;
			while (a != 0) {
				d += pow(a % 10, p);
				a /= 10;
			}
		}
		else break;

		a = d;
	}

	cout << chk[a] - 1;

	return 0;
}
