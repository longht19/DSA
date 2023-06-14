/**
 * @file SCTDL085.cpp
 * @author Long (you@domain.com)
 * @brief BDN number is a number that only includes 0&1 meaningfully.
 * Find the number of BDN numbers less than or equal to N
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string n, k;
bool check(string s)
{
	return s.size() < n.size() || (s.size() == n.size() && s <= n);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int d = 0;
		cin >> n;
		stack<string> st;
		st.push("1");
		while (st.size())
		{
			k = st.top();
			d++;
			st.pop();
			if (check(k + "0"))
				st.push(k + "0");
			if (check(k + "1"))
				st.push(k + "1");
		}
		cout << d << endl;
	}
}