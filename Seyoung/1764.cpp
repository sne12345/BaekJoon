#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
	int n, m, i, j, cnt=0;
	string name;
	scanf("%d %d", &n, &m);
	vector<string> nVector;
	vector<string> mVector;
	
	for (i=0; i<n; i++){
		cin>>name;
		nVector.push_back(name);
	}
	
	sort(nVector.begin(), nVector.end()); // n벡터 배열을 정렬한다 
	
	// 받아들임과 동시에 서치하면서 시간을 줄인다 
	// 정렬할 생각? 어림도 없지~  
	
	for(i=0; i<m; i++){
		cin>>name; 
		if(binary_search(nVector.begin(), nVector.end(), name)){
			mVector.push_back(name);
			cnt++;
		}
	}
	// 이진탐색은 정렬이 되어 있다는 전제 하에 찾는다
	// 시작점, 끝점, 찾을 값 3개의 매개변수면 뚝딱?!  
	
	sort(mVector.begin(), mVector.end());
	
	// getline함수는 왜 모든 텍스트를 읽어들이는 지 못하는가?
	
	cout << cnt <<endl; //오래걸려서 쓰지 말라면서..  
	for(i=0; i<mVector.size(); i++){
		cout << mVector[i] << endl;
	}
	
	return 0;
} 
