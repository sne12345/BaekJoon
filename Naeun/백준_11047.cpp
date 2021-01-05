#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int N;
long long int M;
vector<int> v;

int cnt = 0;
int value;

int main(void) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        cin >> value;
        v.push_back(value);
    }
    
    int sum = 0;
    for(int i=N-1; i>=0; i--){
        if(v[i] > M-sum){
            continue;
        }
        while(v[i] <= M-sum){
            
            sum += v[i];
            cnt++;
            if(M == sum){
                printf("%d\n", cnt);
                return 0;
            }
        }
    }
    
    return 0;
}
