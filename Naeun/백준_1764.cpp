
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    
    vector<string> Ncount, answer;
    int N, M, cnt = 0;
    string name;
    
    scanf("%d%d", &N, &M);
    
    for(int i=0; i<N; i++){
        cin >> name;
        Ncount.push_back(name);
    }
    
    sort(Ncount.begin(), Ncount.end());
    
    for(int i=0; i<M; i++){
        cin >> name;
        if(binary_search(Ncount.begin(), Ncount.end(), name)){
            cnt++;
            answer.push_back(name);
        }
    }
    sort(answer.begin(), answer.end());
    
    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++)
        cout << answer[i] << "\n";
    
    return 0;
}
