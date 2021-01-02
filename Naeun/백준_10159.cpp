#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N, M;
vector<int> v[101];
vector<int> v1[101];
int ch[101];
int ch1[101];
int cnt;

void dfs(int num){

    ch[num] = 1;
    for(int i=0; i<v[num].size(); i++){
        if(ch[v[num][i]] == 0){
            cnt++;
            dfs(v[num][i]);
        }
    }
}

void dfs1(int num){

    ch1[num] = 1;
    for(int i=0; i<v1[num].size(); i++){
        if(ch1[v1[num][i]] == 0){
            cnt++;
            dfs1(v1[num][i]);
        }
    }

}

int main(void) {
    
    int a, b;
    
    cin >> N >> M;
    
    for(int i=0; i<M; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v1[b].push_back(a);
    }

    
    for(int i=1; i<=N; i++){
        cnt = 1;
        dfs(i);
        dfs1(i);
        printf("%d\n", N-cnt);
        memset(ch, 0, sizeof(ch));
        memset(ch1, 0, sizeof(ch1));
    }
    
    return 0;
}
