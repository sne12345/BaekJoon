#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	vector<string> name;
	
	int cnt = 0;
	vector<string> rslt;
	
	string str;
	for(int i = 0; i < n + m; i++) {
		cin >> str;
		name.push_back(str);
	}
	
	sort(name.begin(), name.end());
	
	for(int i = 0; i < n + m; i++) {
		if(name[i] == name[i + 1]) {
			cnt++;
			i++;
			rslt.push_back(name[i]);
		}
	}
	
	sort(rslt.begin(), rslt.end());
	
	printf("%d\n", cnt);
	for(vector<string>::iterator i = rslt.begin(); i != rslt.end(); i++){
    	cout << *i << endl;
  	}
}
