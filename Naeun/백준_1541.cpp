#include <stdio.h>
#include <iostream>
using namespace std;

int main(void) {
    
    int total, value;
    int sum = 0;
    char sign;
    
    cin >> total;
    
    while(1){
        cin >> sign;
        if(sign == '\n'){
            break;
        }
        if(sign == '-'){
            cin >> value;
            sum += value;
            
            cin >> sign;
            while(sign != '-'){
                cin >> value;
                sum += value;
                
                cin >> sign;
            }
            total -= sum;
            sum = 0;
        } else {
            cin >> value;
            total += value;
        }
    }
    
    
    return 0;
}
