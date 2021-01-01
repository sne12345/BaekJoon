#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int maxInt = -1;

vector<int> v;
int ch[101];

void dfs(int sum, int depth, int s){
    if(depth == 3){
        if(sum <= M && sum > maxInt){
            maxInt = sum;
        }
        return;
    } else {
        for(int i=s; i<N; i++){
            if(ch[i] == 0){
                ch[i] = 1;
                dfs(sum + v[i], depth + 1, i);
                ch[i] = 0;
            }
        }
    }
}

int main(void) {
    
    int value;
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        cin >> value;
        v.push_back(value);
    }
    
    dfs(0, 0, 0);
    
    printf("%d\n", maxInt);
    
    return 0;
}
