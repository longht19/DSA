// find the number of k-elements sub-array having sum exactly equal to S

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, ans = 1e9;
long long s, a[35];
void Try(int pos, int m, long long d)
{
    if (d == s)
    {
        ans = min(ans, m);
        return;
    }
    for (int i = pos + 1; i <= n; i++)
        if (d + a[i] <= s && m < ans)
            Try(i, m + 1, d + a[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Try(0, 0, 0);
    if (ans == 1e9)
        cout << -1;
    else
        cout << ans;
}