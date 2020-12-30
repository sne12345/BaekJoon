#include <stdio.h>
#include <iostream>
using namespace std;

int isSoSoo(int num){
    if(num == 1)
        return 0;
    
    for(int i=2; i<num; i++){
        if(num % i == 0)
            return 0;
    }
    return 1;
}

int main(void) {
    
    int total, n, cnt = 0;
    cin >> total;
    
    for(int i=0; i<total; i++){
        cin >> n;
        if(isSoSoo(n))
            cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}
