#include <stdio.h>
#include <iostream>
#include <vector>
#define MAX_NUM 25
using namespace std;

int N, S;
int num;
int cnt = 0;
vector<int> v;

void dfs(int n, int input){
    
    if(n == S && input != 0){
        cnt++;
    }
    
    if(input == N)
        return;
    
    for(int i=input; i<N; i++){
        dfs(n + v[i], i+1);
    }
    
}

int main(void) {
    
    cin >> N >> S;
    
    for(int i=0; i<N; i++){
        cin >> num;
        v.push_back(num);
    }
    
    dfs(0,0);
    
    cout << cnt << endl;
    
    return 0;
}
