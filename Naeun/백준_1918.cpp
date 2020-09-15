#include <iostream>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;

int prec(char c){
    switch(c){
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        case '(': case ')': return 0;
    }
    return -1;
}

int main(void) {
    stack<char> op;
    char arr[101];

    scanf("%s", arr);

    for(int i=0; i<strlen(arr); i++){
        if(isupper(arr[i])){
            printf("%c",arr[i]);
            continue;
        }

        switch(arr[i]){
            case '*': case '/': case '+': case '-':
                while(!op.empty() && prec(op.top()) >= prec(arr[i])){
                    printf("%c", op.top());
                    op.pop();
                }
                op.push(arr[i]);
                break;
            case '(':
                op.push(arr[i]);
                break;
            case ')':
                while(op.top() != '('){
                    printf("%c",op.top());
                    op.pop();
                }
                op.pop();
                break;
        }
    }

    while(!op.empty()){
        if(op.top() != '(')
            printf("%c",op.top());
        op.pop();
    }
    printf("\n");

    return 0;
}
