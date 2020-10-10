#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int parent[1001] ;
struct Edge {
 int s, e, val; 
 bool operator<(const Edge &b) {
  return val < b.val;
 }
};

int Find(int i) {
 if (i == parent[i]) return i;
 return parent[i] = Find(parent[i]);
}

void Union(int i, int j) {
 int a = Find(i);
 int b = Find(j);
 if (a == b) return;
 else {
  if (a < b) swap(a, b);
  parent[b] = a;
 }
}
int main() {
 for (int i = 0; i < 1001; i++) {
  parent[i] = i;
 }
 int nv;
 cin >> nv ;

 // Edge 벡터에 값 넣음
 vector v;
 for (int i = 0; i < nv; i++) {
  for (int j = 0; j < nv; j++) {
   Edge e;
   e.v = i;
   e.u = j;
   cin >> e.weight;
   if(j > i)
    v.push_back(e);
  }
 }

 sort(v.begin(), v.end());

 int count = 0;
 long long sum = 0;

 for (int i = 0; i < v.size(); i++) {
  // 현재 간선 개수(count)가 정점의 개수인 nv보다 하나 작을때 탈출
  if (count == nv - 1) break;
  int pu = Find(v[i].u);
  int pv = Find(v[i].v);

  if (pu != pv) {
   Union(pu, pv);
   sum += v[i].weight;
   count++;
  }
 }
 cout << sum << endl;
}
