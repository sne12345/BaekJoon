#include <stdio.h>
#include <iostream>
using namespace std;

int s, f;
int firstNum;
int sum = 0;
int cnt = 0;

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
    
    cin >> s >> f;
    int flag = 0;
    
    for(int i=s; i<=f; i++){
        if(isSoSoo(i)){
            sum += i;
            if(flag == 0){
                firstNum = i;
                flag = 1;
            }
            cnt++;
        }
    }
    
    if(cnt == 0)
        cout << -1 << endl;
    else {
        cout << sum << endl;
        cout << firstNum << endl;
    }
    
    return 0;
}
