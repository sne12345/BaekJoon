#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int num[4];

int sol(int x) {
	int temp = x;
	for (int i = 0; i < 3; i++)
	{
		x = x % 1000 * 10 + x / 1000;
		if (temp > x) temp = x;
	}
	return temp;
}

int main() {

	int number;

	for (int i = 0; i < 4; i++) {
		cin >> num[i];
	}

	int minNum = sol(num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3]);
	int cnt = 0;
	for (int i = 1111; i <= minNum; i++)
	{
		if (sol(i) == i) cnt++;
	}
	cout << cnt;
}
