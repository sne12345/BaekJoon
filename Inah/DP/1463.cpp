#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int x;
	int rslt[1000000];
	cin >> x;

	rslt[1] = 0;
	for (int i = 2; i <= x; i++) {
		rslt[i] = rslt[i - 1] + 1;
		if (i % 2 == 0) {
			rslt[i] = min(rslt[i], rslt[i / 2] + 1);
		}
		if (i % 3 == 0) {
			rslt[i] = min(rslt[i], rslt[i / 3] + 1);
		}
	}

	cout << rslt[x];

	return 0;
}
