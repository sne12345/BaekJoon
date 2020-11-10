#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

queue<int> q;

int F, S, G, U, D;
int used[1000001];

int main() {
	// 입력
	cin >> F >> S >> G >> U >> D;

	q.push(S);
	int btn = 0; 
	int cur;
	int size;
	used[S] = 1;

	while (true) {

		size = q.size();
		
		if (size == 0) {
			cout << "use the stairs" << endl;
			return 0;
		}

		for (int i = 0; i < size; i++) {
			cur = q.front();
			q.pop();

			// 목적지 도착
			if (cur == G) {
				cout << btn << endl;
				return 0;
			}

			if (cur + U <= F && used[cur + U]==0) {
				used[cur + U] = 1;
				q.push(cur + U);
			}

			if (cur - D >= 1 && used[cur - D] == 0) {
				used[cur - D] = 1;
				q.push(cur - D);
			}
		
		}

		btn++;
	}
}
