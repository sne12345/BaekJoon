#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

int map[50][50], ch[50][50];


int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};
int w, h; //w, h

void DFS(int x, int y){
	int xx, yy;
	ch[x][y]=1;
	
	for(int i=0; i<8; i++){
		xx = x+dx[i];
		yy = y+dy[i];
			
		if(xx<0||xx>=h||yy<0||yy>=w) continue; 
		// 범위 넘어가면 끝내기 
		 
		if(ch[xx][yy]==0 && map[xx][yy]==1){
			DFS(xx, yy);
			// 뒤로 갈 것돋 없이 끝나면 자동 반환임 
			// 어차피 연결될 놈이면 무조건 한 선에 연결되니까
			// 굳이 돌아가서 다른 방식을 찾을 필요가 없음  
		}
	}
		
}



int main(void){
	freopen("input.txt", "rt", stdin);
	int i, j;
	int cnt;
	while(true){
		scanf("%d %d", &w, &h);
		if(w==0 && h==0){
			return 0;
		}
		
		for(i=0; i<h; i++){
			for(j=0; j<w; j++){
				scanf("%d", &map[i][j]);
				// 와 꼼수부리기 금지
				// 데이터를 다 넣어야만 DFS 돌아갈 때 온전히 탐색하는데
				// scanf 한 동시에 탐색하니까 결과가 엉망진창 나오지 ㄷㄷ  
			}
		}
		
		cnt=0;
		
		for(i=0; i<h; i++){
			for(j=0; j<w; j++){
				if(ch[i][j]==0&&map[i][j]==1){
					DFS(i, j); //섬에 해당하는 점만 DFS 돌기
					// 기존의 처음부터 끝까지 도는 DFS랑은 다른 접근 방식  
					
					// 섬의 길이가 아무리 길어도 어쨌건
					// DFS가 다 돌고 반환되는 순간 섬의 개수는 1개 추가되는 것  
					cnt++;
				}
			}
		}
		
		
		printf("%d\n", cnt);
 
		memset(ch, 0, sizeof(ch));
		memset(map, 0, sizeof(map));
		
	}

	
	

}

