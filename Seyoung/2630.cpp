#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int arr[130][130];
int w, b;
 
void check(int size, int startX, int startY){
	// 체크를 시작할 위치의 색을 target에 저장하기
	int target = arr[startX][startY];
	
	for(int x=startX; x<startX+size; x++){
		for(int y = startY; y < startY + size; y++) { 
		if(arr[x][y] != target) { 
			// 다른 색 종이 발견 되면 size를 반으로 줄여서 4등분 한다  
			check(size/2, startX, startY); 
			check(size/2, startX + size/2, startY); 
			check(size/2, startX, startY + size/2); 
			check(size/2, startX + size/2, startY + size/2); 
			return; 
			} 
		}
	}
	// 모두 같은 색이다  
	if(target==0) w++;
	else b++;	
}
int main(void){
	freopen("input.txt", "rt", stdin);
	int n, i, j;
	scanf("%d", &n);
	
	for(i=0; i<=n; i++){
		for(j=0; j<=n; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	check(n, 0, 0);

	printf("%d %d", w, b); 

}

