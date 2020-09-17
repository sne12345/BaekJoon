#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    
    vector<pair<int,int> > graph;
    int num, a, b;
    
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        scanf("%d", &a);
        scanf("%d", &b);
        graph.push_back({a, b});
    }
    
    sort(graph.begin(), graph.end());
    
    for(int i=0; i<num; i++){
        printf("%d %d\n", graph[i].first, graph[i].second);
    }
    return 0;
}
