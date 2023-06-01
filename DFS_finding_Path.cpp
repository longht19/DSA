#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000+5;
vector<int> near[MAX];
bool visited[MAX] = {false};

int main() {
    int t;
    cin >> t;
    while(t--){
        int N, c, start, end;
        cin >> N >> c >> start >> end;
		
		// transform edges list to adjacent list
        for(int i = 0; i < c; i++) {
            int u1, u2;
            cin>>u1>>u2;
            near[u1].push_back(u2);
        }
        for(int i = 1; i <= N; i++) {
            sort(near[i].begin(), near[i].end());
        }
		
        // finding path
        int front[N];
        stack<int> t1;
        t1.push(start);
        visited[start] = true;

        while(!t1.empty()) {
            int s1 = t1.top();
            t1.pop();
            for(int i = 0; i < near[s1].size(); i++){
                if(visited[near[s1][i]] == false){
                    visited[near[s1][i]] = true;
                    t1.push(s1);
                    t1.push(near[s1][i]);
                    front[near[s1][i]] = s1;
                    break;
                }
            }
        }

        // print result
        stack<int> res; 
        int t2 = end;
        res.push(t2);
        while(t2 != start) {
            t2 = front[t2];
            res.push(t2);
        }
        while(!res.empty()) {
            cout << res.top() << " ";
            res.pop();
        }
		
        // clear
        memset(visited, false, N+1);
        for(int i = 1; i <= N; i++) {
            near[i].clear();
        }
        cout<<endl;
    }
	return 0;
}