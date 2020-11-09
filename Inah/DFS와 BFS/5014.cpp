#include <iostream>
#include <queue>

#define M 1000002

using namespace std;

int main()

{
	int F, S, G, U, D;
	int ele[M] = { 0 };
	int chk[M] = { 0 };
	queue<int> Q;

	cin >> F >> S >> G >> U >> D;

	Q.push(S);
	ele[S] = 0;
	chk[S] = 1;

	while (!Q.empty()) {
		int cs = Q.front();
		Q.pop();

		int ns = cs + U;
		if (0 < ns && ns <= F && !chk[ns]) {
			chk[ns] = 1;
			ele[ns] = ele[cs] + 1;
			Q.push(ns);
		}
		ns = cs - D;
		if (0 < ns && ns <= F && !chk[ns]) {
			chk[ns] = 1;
			ele[ns] = ele[cs] + 1;
			Q.push(ns);
		}
	}

	if (!chk[G]) cout << "use the stairs";
	else cout << ele[G];

	return 0;
}
