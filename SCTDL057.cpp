/**
 * @file SCTDL057.cpp
 * @author your name (you@domain.com)
 * @brief Given n elements array A that does not contain
 * 2 same elements.
 * Find K = Floor(X). 
 * K is maximum element of A less than of equal to X
 * @version 0.1
 * @date 2023-06-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    // {
        int n{7}, x{10};
        // cin >> n >> x;
        vector<long long> a = {1, 2, 8, 10, 11, 12, 19};
        // for (int i = 0; i < n; i++)
        //     cin >> a[i];
        a[n + 1] = 1e18;
        int ans = lower_bound(a.begin(), a.end() - 1, x) - a.begin();
        if (a[ans] != x)
            ans--;
        if (ans != -1)
            ans++;
        cout << ans << endl;
    // }
}