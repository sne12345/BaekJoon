#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	priority_queue<int> Q;
	int x;
	int cost = 0, subCost;
	
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		scanf("%d", &x);
		Q.push(-x);
	}
	
	if(Q.size() == 1) Q.pop();
	
	while(!Q.empty()) {
		subCost = 0;
		if(Q.size() == 1) {
			cost += -Q.top();
			Q.pop();
			break;
		}
		cost += -Q.top();
		subCost += -Q.top();
		Q.pop();
		cost += -Q.top();
		subCost += -Q.top();
		Q.pop();
		
		printf("size : %d, cost : %d, subCost : %d\n", Q.size(), cost, subCost);
		
		if(!Q.empty()) 
		{
		Q.push(-subCost);
		
		printf("top : %d, size : %d\n", Q.top(), Q.size());	
		}
	}
	
	printf("%d", cost);
}
