#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring> // memset
 
#define MAX_SIZE 100 + 1
using namespace std;
 
struct tomato {
    int z, y, x;
};
 
queue<tomato> q;
 
// 위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dy[6] = { 0, 0, 0, 0, 1, -1 };
int dz[6] = { 1, -1, 0, 0, 0, 0  };
 
int n, m, h, result = 0;
int graph[MAX_SIZE][MAX_SIZE][MAX_SIZE];
 
bool IsInside(int nz, int ny, int nx) {
    return (0 <= nx && 0 <= ny && 0 <= nz && nx < m && ny < n && nz < h);
}
 
void bfs(void) {
    while (!q.empty()) {
        
        int z = q.front().z;
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
 
        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];
 
            if (IsInside(nz,ny,nx) == 1 && graph[nz][ny][nx] == 0) {
                graph[nz][ny][nx] = graph[z][y][x] + 1;
                q.push({ nz, ny, nx });
            }
        }
    }
}
 
int main() {
    scanf("%d %d %d", &m, &n, &h);
 
    for (int k = 0; k < h; k++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                    scanf("%d", &graph[k][i][j]);
                    if (graph[k][i][j] == 1) {
                        q.push({ k, i, j });
                }
            }
        }
    }
 
    bfs();
 
    for (int k = 0; k < h; k++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                    if (graph[k][i][j] == 0) {
                        printf("-1\n");
                        return 0;
                    }
                    if (result < graph[k][i][j]) {
                        result = graph[k][i][j];
                }
            }
        }
    }
    printf("%d\n", result-1);
    return 0;
}
