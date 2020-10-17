#include <iostream>

using namespace std;

int main()
{
	int arr[101][101] = { 0 };
	int visited[101][101] = { 0 };
	int cnt = 0;
	int x1, y1, x2, y2;

	for (int i = 0; i < 4; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				if (!visited[y][x]) {
					visited[y][x] = 1;
					cnt++;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}