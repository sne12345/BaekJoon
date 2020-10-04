
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;

int main(void)
{
	//freopen("input.txt", "rt", stdin);
	int n, sum = 0, a;
	priority_queue<int> pQ;
	scanf("%d", &n);

	int x, y;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		pQ.push(-a); //최소 힙 
	}

	for (int i = 0; i < n; i++) {
		x = - pQ.top(); pQ.pop();
		y = - pQ.top(); pQ.pop();

		sum = sum + x + y;
		
		if (pQ.empty()) break;
		pQ.push(-(x + y));
	}

	printf("%d", sum);
}
