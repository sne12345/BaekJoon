#include <stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;

int map[51][51], ch[51][51], cnt = 0;
int w, h;

int dx[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

void DFS(int x, int y){
    int xx, yy;
    for(int i=0; i<8; i++){
        xx = x + dx[i];
        yy = y + dy[i];
        
        if(xx < 1 || xx > w || yy < 1 || yy > h){
            continue;
        } else {
            if(map[xx][yy] == 1 && ch[xx][yy] == 0){
                ch[xx][yy] = 1;
                DFS(xx, yy);
            }
        }
    }
}

void init(){
    cnt = 0;
    memset(map, 0, sizeof(map));
    memset(ch, 0, sizeof(ch));
}

int main(void) {
    
    while(1){
        scanf("%d%d", &w, &h);
        if(w == 0 && h == 0){
            break;
        }
        
        for(int j=1; j<=h; j++){
            for(int i=1; i<=w; i++){
                scanf("%d", &map[i][j]);
            }
        }
        
        for(int j=1; j<=h; j++){
            for(int i=1; i<=w; i++){
                if(map[i][j] == 1 && ch[i][j] == 0){
                    ch[i][j] = 1;
                    DFS(i, j);
                    cnt++;
                }
            }
        }
        
        printf("%d\n", cnt);
        init();
    }
    return 0;
}
