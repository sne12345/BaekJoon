#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<pair<int, int> > v;
	
	scanf("%d", &n);
	
	int x, y;
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
}
