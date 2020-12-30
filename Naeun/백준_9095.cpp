#include <stdio.h>
#include <iostream>
#define MAX_NUM 10
using namespace std;

int ch[MAX_NUM];
int num[3] = {1,2,3};
int sum, cnt = 0;
int n;


void dfs(int total){
    if(total > sum){
        return;
    }
    
    if(total == sum){
        cnt++;
        return;
    } else {
        for(int i=0; i<3; i++){
            dfs(total + num[i]);
        }
    }
}

int main(void) {
    
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cnt = 0;
        
        cin >> sum;
        dfs(0);
        cout << cnt << endl;
    }
    
    return 0;
}
