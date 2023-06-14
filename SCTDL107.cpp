/**
 * @file SCTDL107.cpp
 * @author your name (you@domain.com)
 * @brief BFS : non-directional graph representation
 * @version 0.1
 * @date 2023-06-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, x, y;
        cin >> n >> m >> u;
        vector<int> a[n + 1], notVisited(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            sort(a[i].begin(), a[i].end());
        }
        queue<int> q;
        q.push(u);
        notVisited[u] = 0;
        while (q.size())
        {
            u = q.front();
            q.pop();
            cout << u << " ";
            for (int i = 0; i < a[u].size(); i++)
            {
                int v = a[u][i];
                if (notVisited[v])
                {
                    q.push(v);
                    notVisited[v] = 0;
                }
            }
        }
        cout << endl;
    }
}