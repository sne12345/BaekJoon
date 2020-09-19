#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

bool visited[1001];
int array[1001];

bool DFS(int n){
	visited[n]=true;
	
	int next = array[n];
	if(!visited[next]){
		DFS(next);
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
	int T, n, a;
	scanf("%d", &T);
	
	
	// 순열이 결국 간선들의 배열인데, 이걸 어떻게 그래프로 연결하나 했더니
	// arr[1] = 3 하면 배열 1번 위치에 3으로 연결하고
	// arr[arr[1]] 로 불러들이면 arr[1]의 값이 연결된,
	// 결과적으로는 arr[3] 을 불러들이는 논리 
	
	 
	for(int i=1; i<=T; i++){
		scanf("%d", &n); // 순열 배열 개수
		
		// 배열 개수만큼 입력받기  
		for(int j=1; j<=n; j++){
			scanf("%d", &array[j]);
		}
		
		memset(visited, false, sizeof(visited)); // visited 배열 초기화 
		
		int cnt=0; // 순열 사이클 개수
		
		for(int k=1; k<=n; k++){
			if(!visited[k]){
				DFS(k);
				cnt++;
			}
		}
		
		printf("%d\n", cnt);
	} 

	return 0;
} 	

