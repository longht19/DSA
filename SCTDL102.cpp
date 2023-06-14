/**
 * @file SCTDL102.cpp
 * @author your name (you@domain.com)
 * @brief Adjacent matrix to adjacent list
 * @version 0.1
 * @date 2023-06-12
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
    int n, x;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            if (i > j && x == 1)
            {
                a[i].push_back(j);
                a[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (auto j : a[i])
            cout << j << " ";
        cout << endl;
    }
}