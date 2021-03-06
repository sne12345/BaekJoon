#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int> > graph;
int visited[10000] = {0};

void DFS(int num)
{
   visited[num] = 1;
   
   for(int i = 0; i < graph[num].size(); i++) {
      if(!visited[graph[num][i]]) {
         DFS(graph[num][i]);
      }
   }
}

int main()
{
   cin >> n >> m;
   
   graph.resize(n + 1);
   
   int u, v;
   for(int i = 0; i < m; i++) {
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
   }
      
   int cnt = 0;
   for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
         DFS(i);
         cnt++;
      }
   }
   cout << cnt << endl;
}
