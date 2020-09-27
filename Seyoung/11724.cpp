#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

vector<int> map[1001];
int n; 
int ch[1001];

void DFS(int v){
	int i; 
	ch[v]=1; //탐색했다는 표시
	
	for(i=0; i<map[v].size(); i++){
		if(ch[map[v][i]]==0){
			DFS(map[v][i]);
		}	
	}	
}

int main(void){
	freopen("input.txt", "rt", stdin);

	int m, i, a, b;
	scanf("%d %d", &n, &m);
	
	// 인접리스트  모두 입력  
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		// 무방향은 곧 양방향이다 !!!  
		map[a].push_back(b); 
		map[b].push_back(a); 
	}
	
	int cnt=0;
	
	// 인접리스트 정점별 dfs 탐색  
	for(i=1; i<=n; i++){
		if(ch[i]==0){ //방문한 적 없을 때만 탐색  
			DFS(i);
			cnt++;
		}
	}
	
	printf("%d", cnt);
	
}

