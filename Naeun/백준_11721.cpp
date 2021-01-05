#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    
    string str;
    
    cin >> str;
    
    for(int i=0; i<=str.length(); i=i+10){
        cout << str.substr(i, 10) << "\n";
    }
    
    return 0;
}
