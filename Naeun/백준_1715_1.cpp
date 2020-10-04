#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
 
priority_queue <long long int> pq;
long long int sum, cnt;
 
int main()
{
    int n, val;
    long long int res;
 
    cin >> n;
 
    if (n == 1)
    {
        cin >> val;
        printf("0");
        return 0;
    }
 
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        pq.push(-val);
    }
 
    while (!pq.empty())
    {
        res = pq.top();
        pq.pop();
 
        res += pq.top();
        pq.pop();
 
        sum += res;
 
        if(!pq.empty())
            pq.push(res);
    }
 
    cout << -sum << "\n";
 
    return 0;
}
