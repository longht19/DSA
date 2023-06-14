/**
 * @file SCTDL043.cpp
 * @author long (you@domain.com)
 * @brief Tasks sorting function
 * @version 0.1
 * @date 2023-03-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n = 6;
		cin >> n;
		// pair<int, int> a[n] = {{2, 1}, {4, 3}, {6, 0}, {7, 5}, {9, 8}, {9, 5}};
        pair<int, int> a[n];
		for (int i = 0; i < n; i++)
        {
			cin >> a[i].second;
        }
        for (int i = 0; i < n; i++)
		{
        	cin >> a[i].first;
        }
        sort(a, a + n);
		int ans = 1, k = a[0].first;
		for (int i = 1; i < n; i++)
		{
			if (a[i].second >= k)
			{
				ans++;
				k = a[i].first;
			}
		}
		cout << ans << endl;
	}
}