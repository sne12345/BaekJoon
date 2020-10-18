#include <iostream> 
#include <algorithm>

#define SIZE 4

using namespace std;

int findClockNum(int a)
{
	int min = a;

	for (int i = 0; i < 3; i++) {
		a = a % 1000 * 10 + a / 1000;
		if (min > a) min = a;
	}

	return min;
}
int main()
{
	int num[SIZE], minN;
	int cnt = 0;

	for (int i = 0; i < SIZE; i++) {
		cin >> num[i];
	}

	minN = findClockNum(num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3]);

	for (int i = 1111; i <= minN; i++) {
		if (findClockNum(i) == i) cnt++;
	}

	cout << cnt << endl;
}
