#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int isAlphabet(char c)
{
	return 'A' <= c && c <= 'Z';
}
int isOperator(char c) 
{
	char op[4] = {'+', '-', '*', '/'};
	
	for(int i = 0; i < 4; i++) {
		if(c == op[i]) return 1;
	}
	return 0;
}
void insertOperator(vector<char> v, stack<char> s)
{
	while(!s.empty()) {
		v.push_back(s.top());
		s.pop();
	}
}
void printVector(vector<char> v)
{
	for(int i = 0; i < v.size(); i++){
		printf("%c", v[i]);
	}
}
int main()
{
	vector<char> rslt;
	stack<char> op;
	char eq[1000];
	
	scanf("%s", eq);
	
	for(int i = 0; eq[i] != '\0'; i++) {
		if(!isOperator(eq[i])) {
			if(eq[i] == '(') i++;
			if(isAlphabet(eq[i])) rslt.push_back(eq[i]);
			if(eq[i] == ')') {
				while(!op.empty()) {
					rslt.push_back(op.top());
					op.pop();
				}
			}
		}
		else {
			if(eq[i] == '*' || eq[i] == '/') {
				while(!op.empty()) {
					if(op.top() == '*' || op.top() == '/') {
						rslt.push_back(op.top());
						op.pop();
					}
					else{
						break;
					}
				}
			}
			if(eq[i] == '+' || eq[i] == '-') {
				while(!op.empty()) {
					if(op.top() == '+' || op.top() == '-') {
						op.pop();
						rslt.push_back(op.top());
					}
					else{
						break;
					}
				}
			}
			op.push(eq[i]);	
		}
	}
	
	printVector(rslt); 
}
