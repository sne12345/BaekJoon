#include <iostream> 
#include <algorithm>

#define SIZE 4

using namespace std;

int findMinClockNum(int a)
{
	int min = 99999;

	for (int i = 0; i < SIZE - 1; i++) {
		a = a % 1000 * 10 + a / 1000;
		min = a < min ? a : min;
	}

	return min;
}
int main()
{
	int num[SIZE], n = 0, minN;
	int cnt = 1;

	for (int i = 0; i < SIZE; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < SIZE; i++) {
		n *= 10;
		n += num[i];
	}

	minN = findMinClockNum(n);

	for (int i = 1111; i <= n; i++) {
		if (findMinClockNum(i) == i) cnt++;
	}

	cout << cnt << endl;
}