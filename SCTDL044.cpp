/**
 * @file SCTDL044.cpp
 * @author Long (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        long long s = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            q.push(x);
        }
        while (q.size() > 1)
        {
            int s1 = q.top();
            q.pop();
            int s2 = q.top();
            q.pop();
            int k = s1 + s2;
            s += k;
            q.push(k);
        }
        cout << s << "\n";
    }
}