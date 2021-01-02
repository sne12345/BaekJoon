#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int arr[6][6];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1 ,0, 0};
vector<int> v;

int isDistinct(int n){
    for(int i=0; i<v.size(); i++){
        if(n == v[i])
            return 0;
    }
    return 1;
}

void dfs(int x, int y, int depth, int num){
    if(depth == 5){
        if(isDistinct(num)){
            v.push_back(num);
        }
        return;
    } else {
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx >= 0 && nx < 5 && ny >= 0 && ny <5){
                dfs(nx, ny, depth+1, num * 10 + arr[nx][ny]);
            }
        }
    }
}

int main(void) {
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            dfs(i, j, 0, arr[i][j]);
        }
    }

    printf("%d\n", (int)v.size());
    
    return 0;
}
