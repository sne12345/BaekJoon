#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <vector <int> > v;

int ch[101], cnt = 0;

void D(int n){
    ch[n] = 1;
    
    for(int i=0; i<v[n].size(); i++){
        if(ch[v[n][i]] == 0){
            cnt++;
            D(v[n][i]);
        }
    }
}

int main(void) {
    
    int com, n, s, e;
    scanf("%d %d", &com, &n);
    
    v.resize(com+1);
    
    for(int i=0; i<n; i++){
        scanf("%d %d", &s, &e);
        v[s].push_back(e);
        v[e].push_back(s);
    }

    D(1);
    
    printf("%d\n", cnt);
    
    return 0;
}
