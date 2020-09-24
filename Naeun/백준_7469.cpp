#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[100001], arrcopy[100001], tmp[100001];

void divide(int lt, int rt){
    int mid, p1, p2, p3;
    if(lt<rt){
        mid = (lt+rt)/2;
        divide(lt, mid);
        divide(mid+1, rt);
        
        p1 = lt; p2 = mid + 1; p3 = lt;
        while(p1<=mid && p2<=rt){
            if(arrcopy[p1]<arrcopy[p2])
                tmp[p3++] = arrcopy[p1++];
            else
                tmp[p3++] = arrcopy[p2++];
        }
        
        while(p1<=mid)
            tmp[p3++] = arrcopy[p1++];
        while(p2<=rt)
            tmp[p3++] = arrcopy[p2++];
        
        for(int i=lt; i<=rt; i++){
            arrcopy[i] = tmp[i];
        }
    }
}

int main(void) {
    
    int n, m;
    int i, j, k;
    
    scanf("%d%d", &n, &m);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int l=0; l<m; l++){
        
        scanf("%d%d%d",&i, &j, &k);
        for(int p=i; p<=j; p++){
            arrcopy[p-i+1] = arr[p];
        }
        
        divide(1, j-i+1);
        printf("%d\n", arrcopy[k]);
    }
    
    return 0;
}
