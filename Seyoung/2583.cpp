#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int m, n, k;
int c;
int arrCount = 0;
int map[110][110];
int arr[10000];
int moveX[4] = { 0, 1, 0, -1 }; // x좌표 방향 
int moveY[4] = { 1, 0, -1, 0 }; // y좌표 방향  
 
void DFS(int a, int b)
{
	// 탈출 조건: 방문한 적 있을 경우임  
	if (map[a][b] == 0) {
		map[a][b] = 1;
		++c; // 방문한 적 없을 때 1로 체크하고 영역 수 늘리기  
		for (int l = 0; l < 4; ++l) { // 해당위치로부터 위쪽, 오른쪽, 아래쪽, 왼쪽 탐색 시작함  
			int x = moveX[l] + a; // 이건 알겠어  
			int y = moveY[l] + b;
			if (x >= 0 && y >= 0 && x < m && y < n) { // (5, 5) 마지막 경계는 뺌
		 		// 해당 영역이 평면 좌표 경계 안에 있으면 탐색 다시 시작
				// 계속 안으로 들어가는 깊이 탐색  
				DFS(x, y);
			}
		}
	}
}
 
int main(int argc, char *argv[])
{
	int x1, y1, x2, y2;
 	
	memset(map, 0, sizeof(map));
	memset(arr, 0, sizeof(arr));
 
 	freopen("input.txt", "rt", stdin); 
	cin >> m;
	cin >> n;
	cin >> k;
 
	while (k--) {
		cin >> x1 >> y1;
		cin >> x2 >> y2;
 
		for (int i = x1; i < x2; ++i) {
			for (int j = y1; j < y2; ++j) {
				map[j][i] = 1; // 일단 사각형들은 1로 채우고  
				printf("x: %d y: %d\n", i, j); // 가장 숫자가 큰 좌표 x, y에 대해서는 카운트 하지 않음  
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == 0) { // 1 아닌, 사각형 면적에 포함되지 않는 부분들의 영역을 찾기 위한 DFS 탐색 시작함 
				c = 0; // 일단 영역 개수 0으로 설정  
				// 단순히 숫자를 세는게 어떻게 사각형의 전체 넓이를 세는 건지 이해가 안됨  
				DFS(i, j);
				arr[arrCount++] = c; // 영역들을 저장할 배열에 구해진 영역 저장하기  
			}
		}
	}
	sort(arr, arr + arrCount); // 예쁘게 보이기 위해 정렬하기  
 
	cout << arrCount << endl;
 
	for (int i = 0; i < arrCount; ++i) {
		cout << arr[i] << " "; // 영역 하나씩 넓이 얼마인지 출력하기  
	}
 
	return 0;
}
