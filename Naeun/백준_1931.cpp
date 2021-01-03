#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int N;
int a, b;
vector<int> v[100001];

void dfs(int cnt){
    
}

int main(void) {
    
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> a >> b;
        v[a].push_back(b);
    }
    
    
    return 0;
}
