/**
 * @file SCTDL060.cpp
 * @author long (you@domain.com)
 * @brief Given an array only includes 0 & 1 elements.
 * Count the number of '0' elements in array.
 * '0' elements only are front of '1' elements.
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // using lower_bound() to find an iterator pointing to the first element
        // in range [a, a+n] which has a value not less than 1.
        // - a: return to index in array a by minus to a(beginning iterator).
        int m = lower_bound(a, a + n, 1) - a;
        cout << m << endl;
    }
}