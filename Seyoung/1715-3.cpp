#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;

int main(void)
{
	freopen("input.txt", "rt", stdin);
	int n, sum = 0, a;
	priority_queue<int, vector<int>, greater<int> > pQ;
	scanf("%d", &n);

	int x, y;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		pQ.push(a); //최소 힙 
	}

  // 메모리 초과 에러나는 경우는 for문으로 0부터 n까지 돌렸을 때인데 (결과는 일치함)
  // while 루프로 처리하니까 for문보다 메모리 소모양이 적은 듯하다.
  
	while(true){
		if (pQ.size() == 1) {
			printf("%d", sum);
			break;
		}

		x = pQ.top(); pQ.pop();
		y = pQ.top(); pQ.pop();

		sum = sum + x + y;

		pQ.push(x + y);
	}

}
