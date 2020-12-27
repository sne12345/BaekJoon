#include <iostream>
#include <vector>

#define MAX 10001

using namespace std;

vector<int> tree;

void preToPost(int s, int e)
{
	int ans = s;
	int sub = s++; // 좌,우 서브트리를 나누는 인덱스
	while (tree[++sub] < tree[ans]); // 인덱스 계산
	// 좌측 서브트리
	if (s <= sub - 1)
		preToPost(s, sub - 1);
	// 우측 서브트리
	if (sub <= e)
		preToPost(sub, e);
	
	cout << tree[ans] << endl;
}
int main()
{
	int t;

	while (cin >> t) {
		tree.push_back(t);
	}

	preToPost(0, tree.size());

	return 0;
}
