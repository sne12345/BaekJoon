#include <iostream>

#include <algorithm>

#include <cstring> 

using namespace std;

const int MAX = 10000 + 1;

int N;

int graph[MAX][MAX];
bool visited[MAX];
int cache[MAX][MAX];

int getDiameter(int start, int node)
{
        int &result = cache[start][node];

        if (result != -1) return result;

        result = 0;

        for (int i = 1; i <= N; i++) {
			if (graph[node][i] && !visited[i]) {
				visited[i] = true;
				result = max(result, graph[node][i] + getDiameter(start, i));
				visited[i] = false;
			}          
		}
        return result;
}

int main(void)
{
        cin >> N;

        int node1, node2, weight;
        for (int i = 0; i < N - 1; i++) {
            scanf("%d %d %d", &node1, &node2, &weight);
            graph[node1][node2] = weight;
            graph[node2][node1] = weight;
        }

        memset(cache, -1, sizeof(cache));

        int result = 0;

        for (int i = 1; i <= N; i++) {
            memset(visited, false, sizeof(visited));
            visited[i]=true;
            result = max(result, getDiameter(i, i));
        }

        printf("%d", result);
        return 0;
}
