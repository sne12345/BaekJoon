#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int arr[100001];
int temp[100001];
int smallTemp[100001];

void mergeSort(int lt, int rt){
	int mid;
	int p1, p2, p3;
	if(lt<rt){
		mid=(lt+rt)/2;
		mergeSort(lt, mid);
		mergeSort(mid+1, rt);
		
		p1=lt;
		p2=mid+1;
		p3=lt;
		
		while(p1<=mid&&p2<=rt){
			if(temp[p1]>=temp[p2]) smallTemp[p3++]=temp[p1++];
			else smallTemp[p3++]=temp[p2++];
		}
		
		while(p1<=mid) smallTemp[p3++]=temp[p1++];
		while(p2<=rt) smallTemp[p3++]=temp[p2++];
		
		// 원 배열로 다시 바꾸는 작업
		for(int i=lt; i<=rt; i++){
			temp[i]=smallTemp[i]; //복사하기  
			//printf("%d ", temp[i]);
			//printf("%d\n");
		} 
	}
}

int q(int lt, int rt, int index){
	int j=1;
	for(int i=lt; i<=rt; i++){
		temp[j++]=arr[i]; //새로 배열 옮겨 넣기 
	}
	
	mergeSort(1, --j);
	return temp[index];
}



int main(void){
	freopen("input.txt", "rt", stdin);
	int i, n, m;
	int a, b, c;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &arr[i]);
	}
	
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		printf("%d", q(a, b, c));
	}
}

