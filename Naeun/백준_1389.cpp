#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define MAX_SIZE 10001
using namespace std;

int ch[MAX_SIZE], dis[MAX_SIZE], sum[MAX_SIZE];
int minRel = 12345;
int minId;

vector<int> map[MAX_SIZE];
queue<int> Q;

int main(void) {
    int n, m, a, b, x;
    
    scanf("%d%d", &n, &m);  // 유저 수, 관계 수
    
    for(int i=1; i<=m; i++){
        scanf("%d%d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
    
    
    for(int k=1; k<=n; k++){
        
        // 초기화 : ch, dis
        memset(ch, 0, sizeof(ch));
        memset(dis, 0, sizeof(dis));
        
        Q.push(k);
        ch[k] = 1;
        
        while(!Q.empty()){
            x=Q.front();
            Q.pop();
            for(int i=0; i<map[x].size(); i++){
                if(ch[map[x][i]] == 0){
                    ch[map[x][i]] = 1;
                    Q.push(map[x][i]);
                    dis[map[x][i]] = dis[x] + 1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            // i 가 시작 노드와 같은 경우 처리
            if(i == k)
                continue;
            sum[k] += dis[i];
        }
        
    }
    
    
    // 최저값 출력
    for(int i=1; i<=n; i++){
        //printf("%d\n", sum[i]);
        if(sum[i] < minRel){
            minRel = sum[i];
            minId = i;
        }
    }
    printf("%d\n", minId);
    
    return 0;
}
