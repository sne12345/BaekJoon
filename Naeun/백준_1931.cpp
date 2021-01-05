    #include <stdio.h>
    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    int N, a, b;
    int cnt;
    vector< pair<int, int> > v;

    bool compare(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first < b.first;
        } else {
            return a.second < b.second;
        }
    }

    int main(void) {
        
        cin >> N;
        
        for(int i=0; i<N; i++){
            cin >> a >> b;
            v.push_back({a, b});
        }
        
        sort(v.begin(), v.end(), compare);
        
        
        int startIdx = 0;
        cnt = 1;
        
        for(int i=1; i<N; i++){
            if(v[i].first >= v[startIdx].second){
                cnt++;
                startIdx = i;
            }
        }
        
        printf("%d\n", cnt);
        
        return 0;
    }
