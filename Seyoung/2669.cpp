#include <iostream>

using namespace std;

int sq[101][101];
int cnt = 0;
void color(int ax, int ay, int bx, int by) {

	for (int i = ax; i <= bx; i++) {
		for (int j = ay; j <= by; j++) {
			if (sq[i][j]) continue;
			sq[i][j] = 1;
			cnt++;
		}
	}
}

int main() {

	int ax, ay, bx, by;
	
	for (int i = 0; i < 4; i++) {
		cin >> ax >> ay >> bx >> by;
		color(ax, ay, bx - 1, by - 1);
	}

	cout << cnt << endl;
}
