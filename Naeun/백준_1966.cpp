#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int total;
    int N, M, value;
    queue<int> qM;
    queue<int> qS;
    
    cin >> total;
    
    for(int k=0; k<total; k++){
        
        cin >> N >> M;
        
        for(int i=0; i<N; i++){
            cin >> value;
            qM.push(value);
            
            if(i == M){
                qS.push(1);
            } else {
                qS.push(0);
            }
        }
        
        int cnt = 0;
        int flag;
        while(!qM.empty()){
            int x = qM.front();
            int y = qS.front();
            int size = (int)qM.size();
            qM.pop();
            qS.pop();
            
            flag = 1;
            for(int i=0; i<size-1; i++){
                
                if(qM.front() > x){
                    flag = 0;
                }
                qM.push(qM.front());
                qS.push(qS.front());
                
                qM.pop();
                qS.pop();
            }
            
            if(flag == 1){
                cnt++;
                if(y == 1) break;
            }
            else if(flag == 0){
                qM.push(x);
                qS.push(y);
            }
            
            
        }
        
        printf("%d\n", cnt);
        
        while(!qM.empty() || !qS.empty()){
            qM.pop();
            qS.pop();
        }
    }
    
    return 0;
}
