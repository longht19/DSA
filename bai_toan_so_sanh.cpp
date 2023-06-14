#include <bits/stdc++.h>
using namespace std;

map<string, string> parent;

string find(string u, string x){
	if(u != parent[u]){
		if(parent[u] == x)
			return x;
		return find(parent[u], x);
	}
	else
		return parent[u];
}

bool Union(string x, string y){
	x = find(x, y);
	if(x == y)
		return true;
	parent[y] = x;
	return false;
}

int main()
{
	string res = "possible";
	int n; cin >> n;
	vector<string> tmp;
	for(int i = 0; i < n; i++){
		string a, b, c;
		cin >> a >> b >> c;
		tmp.push_back(a);
		tmp.push_back(b);
		tmp.push_back(c);
		parent[a] = a;
		parent[c] = c;
	}
	for(int i = 0; i < tmp.size(); i += 3){
		if(tmp[i + 1] == ">"){
			if(Union(tmp[i], tmp[i + 2])){
				res = "impossible";
				break;
			}
		}
		else
		{
			if(Union(tmp[i + 2], tmp[i])){
				res = "impossible";
				break;
			}				
		}
	}
	cout << res << endl;
}

