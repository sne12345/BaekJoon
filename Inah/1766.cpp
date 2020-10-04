#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	int x, y;
	int arr[32004];
	vector<int> V[32004];
	priority_queue<int, vector<int>, greater<int> > Q;
	
	scanf("%d %d", &N, &M);
	
	for(int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		V[x].push_back(y);
		arr[y]++;
	}
	
	for(int i = 1; i <= N; i++) if(!arr[i]) Q.push(i);
	
	while(!Q.empty()) {
		int h= Q.top();
		Q.pop();
		
		printf("%d ", h);  
		for(int j = 0; j < V[h].size(); j++) {
			int t = V[h][j];
            arr[t]--; 
            if(!arr[t]) Q.push(t);  
        }  
	}
}
