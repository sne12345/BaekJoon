#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int ch[101];

int main(void) {
    int n, m, a, b, x, cnt = 0;
    
    vector<int> map[101];
    queue<int> Q;
    scanf("%d%d", &n, &m);      // 두 줄에 나눠서 입력해도 가능한가? 가능!
    
    for(int i=1; i<=m; i++){
        scanf("%d%d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
    
    Q.push(1);
    ch[1] = 1;
    
    while(!Q.empty()){
        x=Q.front();
        Q.pop();
        for(int i=0; i<map[x].size(); i++){
            if(ch[map[x][i]] == 0){
                ch[map[x][i]] = 1;
                Q.push(map[x][i]);
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    
    return 0;
}


/*
 1 2 5
 2 1 3 5
 3 2
 4 7
 5 1 2 6
 6 5
 7 4
 */

/*
 1 2 5
 2 3
 3
 4 7
 5 2 6
 6
 7
 */
