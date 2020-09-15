#include <iostream>
#include <string.h>

using namespace std;

int arr[10000];
int top = -1;

void push(int x)
{
	arr[++top] = x;
}
void pop()
{
	if(top == -1) cout << -1;
	else cout << arr[top--];
}
int size()
{
	return top + 1;
}
int empty()
{
	return size() > 0 ? 0 : 1;
}
void peek()
{
	if(top == -1) cout << -1;
	else cout << arr[top];
}

int main()
{
	int n, x;
	scanf("%d", &n);
	
	char cmd[100];
	for(int i = 0; i < n; i++) {
		scanf("%s", cmd);
		fgetc(stdin);
		
		if(!strcmp(cmd, "push")) {
			scanf("%d", &x);
			push(x);
		} 
		else if(!strcmp(cmd, "pop")) pop();
		else if(!strcmp(cmd, "size")) cout << size();
		else if(!strcmp(cmd, "empty")) cout << empty();
		else if(!strcmp(cmd, "top")) peek();
	}
}
