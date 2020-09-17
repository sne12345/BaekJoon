#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool compare(pair<int, int> a, pair <int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else
		return a.first < b.first;
}

int main(){
	freopen("input.txt", "rt", stdin);
	int i, n, x, y; 
	scanf("%d", &n);
	
	vector<pair<int, int> > graph;
	
	for(i=0; i<n; i++){
		scanf("%d %d", &x, &y);
		graph.push_back(make_pair(x, y));
	}
	
	sort(graph.begin(), graph.end(), compare);
	
	for(i=0; i<graph.size(); i++){
		printf("%d %d\n", graph[i].first, graph[i].second);
	}
} 	

