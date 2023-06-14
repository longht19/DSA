#include <bits/stdc++.h>
using namespace std;

int n, m, parent[1005];
string res = "";

void init()
{
	for(int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	res = "NO";
}

int find(int u, int x)
{
	if(u != parent[u]){
		if(parent[u] == x){
			return x;
		}
		return find(parent[u], x);
	}
	return parent[u];
}

void Union(int x, int y)
{
	if(res == "YES")
		return;
		
	int a = find(x, y);
	int b = y;
	if(a == b)
	{
		res = "YES";
		return;
	}
	parent[b] = a;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		init();
		for(int i = 1; i <= m; i++)
		{
			int x, y;
			cin >> x >> y;
			Union(x, y);
		}
		cout << res << endl;
	}
}



