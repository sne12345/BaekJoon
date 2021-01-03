#include <stdio.h>
#include <iostream>
#include <deque>
using namespace std;

int main(void) {
    
    int N, value;
    string s;
    deque<int> dq;
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> s;
        
        if(s == "push_back"){
            cin >> value;
            dq.push_back(value);
        } else if(s == "push_front"){
            cin >> value;
            dq.push_front(value);
        } else if(s == "front") {
            if(dq.empty()){
                printf("-1\n");
            } else {
                printf("%d\n", dq.front());
            }
        } else if(s == "back") {
            if(dq.empty()){
                printf("-1\n");
            } else {
                printf("%d\n", dq.back());
            }
        } else if(s == "size") {
            printf("%d\n", (int)dq.size());
        } else if(s == "empty") {
            if(dq.empty()){
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if(s == "pop_back") {
            if(dq.empty()){
                printf("-1\n");
            } else {
                printf("%d\n", dq.back());
                dq.pop_back();
            }
        } else if(s == "pop_front") {
            if(dq.empty()){
                printf("-1\n");
            } else {
                printf("%d\n", dq.front());
                dq.pop_front();
            }
        }
    }
    
    return 0;
}
