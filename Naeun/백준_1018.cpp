#include <stdio.h>
#include <iostream>
using namespace std;

int N, M;
char arr[51][51];

int repaintB(int x, int y){
    
    int cnt = 0;
    
    char stand = 'B';
    for(int i=x; i<x+8; i++) {
        for(int j=y; j<y+8; j++){
            if(arr[i][j] != stand){
                cnt++;
            }
            stand = ( stand == 'W' )? 'B' : 'W';
        }
        stand = ( stand == 'W' )? 'B' : 'W';
    }
    return cnt;
}

int repaintW(int x, int y){
    
    int cnt = 0;
    
    char stand = 'W';
    for(int i=x; i<x+8; i++) {
        for(int j=y; j<y+8; j++){
            if(arr[i][j] != stand){
                cnt++;
            }
            stand = ( stand == 'W' )? 'B' : 'W';
        }
        stand = ( stand == 'W' )? 'B' : 'W';
    }
    return cnt;
}

int main(void) {
    
    int minNum = 3000;
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<N-7; i++){
        for(int j=0; j<M-7; j++){
            int tmpB = repaintB(i, j);
            int tmpW = repaintW(i, j);
            if(tmpB < minNum){
                minNum = tmpB;
            }
            if(tmpW < minNum){
                minNum = tmpW;
            }
        }
    }
    
    printf("%d\n", minNum);
    
    
    return 0;
}
