#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int ch[101], dis[101];
int s, f;

int main(void) {
    int n, m, a, b, x;
    
    vector<int> map[101];
    queue<int> Q;
    scanf("%d", &n);
    scanf("%d%d", &s, &f);
    scanf("%d", &m);
    
    
    for(int i=1; i<=m; i++){
        scanf("%d%d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
    
    Q.push(s);
    ch[s] = 1;
    
    while(!Q.empty()){
        x=Q.front();
        if(x == f)
            break;
        Q.pop();
        for(int i=0; i<map[x].size(); i++){
            if(ch[map[x][i]] == 0){
                ch[map[x][i]] = 1;
                Q.push(map[x][i]);
                dis[map[x][i]] = dis[x] + 1;
            }
        }
    }
    
    if(dis[f] == 0)
        dis[f] = -1;
    printf("%d\n", dis[f]);
    
    return 0;
}
