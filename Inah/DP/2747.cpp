#include <iostream>

#define MAX 46

using namespace std;

int main()
{
	int num, fib[10000];
	cin >> num;

	fib[0] = fib[1] = 1;

	for (int i = 2; i < MAX; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	cout << fib[num - 1];

	return 0;
}
