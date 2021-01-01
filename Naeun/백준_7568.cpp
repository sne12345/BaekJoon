#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct People {
    int height;
    int weight;
} People;

int total;
int h, w;


int main(void) {
    
    People p[51];
    
    cin >> total;
    
    for(int i=0; i<total; i++){
        
        cin >> h >> w;
        
        p[i].height = h;
        p[i].weight = w;
    }
    
    return 0;
}
