#include <iostream>

using namespace std;

int arr[100000];
int a[100000];
	
void merge(int s, int m, int e)
{
	int temp[100000];
	int i = s, j = m + 1, k = 1;
	
	while(i <= m && j <= e) {
//		printf("i : %d, j : %d\n", i, j);
//		printf("a[i] : %d, ", a[i]);
//		printf("a[j] : %d, ", a[j]);
		if(a[i] < a[j]) temp[k++] = a[i++];
		else temp[k++] = a[j++];
//		printf("temp[i] : %d\n", temp[k - 1]);
	}
	
	while(i <= m) temp[k++] = a[i++];
	while(j <= e) temp[k++] = a[j++];
	
	for(int i = s; i <= e; i++) {
		a[i] = temp[i - s + 1];
//		printf("%d ", temp[i - s + 1]);
	}
//	printf("\n");
}
void mergeSort(int s, int e)
{
	int m;
	if(s < e) {
		m = (s + e) / 2;
		mergeSort(s, m);
		mergeSort(m + 1, e);
		merge(s, m, e);
	}
}
int Q(int x, int y, int z)
{
	int n = y - x + 1;
	//int a[n];
	
	for(int i = 1; i <= n; i++) {
		a[i] = arr[i + x - 1];
//		printf("%d ", a[i]);
	}
//	printf("\n");
	
	mergeSort(1, n);
	
	for(int i = 1; i <= n; i++) {
//		printf("%d ", a[i]);
	}
//	printf("\n");
	
	return a[z];
}
int main()
{
	int n, m;
	int x, y, z;
	
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		printf("%d\n" , Q(x, y, z));
	}
}
