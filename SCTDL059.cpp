/**
 * @file SCTDL059.cpp
 * @author long (you@domain.com)
 * @brief Find the unique element in array A that is not in array B.
 * Guarantee that array A is different from array B with only one element.
 * @version 0.1
 * @date 2023-06-10
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
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}