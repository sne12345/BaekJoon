  
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int unf[10001];

struct Edge{
	int s;
	int e;
	int val;
	Edge(int a, int b, int c){
		s=a;
		e=b;
		val=c;
	}
	bool operator<(const Edge &b)const{
		return val<b.val;
	}
};

int Find(int v){
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main(){
	vector<Edge> Ed;
	int i, j, n, w, cnt=0, res=0;
	
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++){
		unf[i] = i;
	}
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++) {
			scanf("%d", &w);
			if(w) Ed.push_back(Edge(i, j, w));
		}
	}
	sort(Ed.begin(), Ed.end());
	for(i = 0; i < Ed.size(); i++){
		int fa = Find(Ed[i].s);
		int fb = Find(Ed[i].e);
		if(fa != fb){
			res += Ed[i].val;
			Union(Ed[i].s, Ed[i].e);
		}
	}
	printf("%d\n", res);
	return 0;
}

