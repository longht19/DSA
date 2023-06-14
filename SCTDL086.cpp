/**
 * @file SCTDL086.cpp
 * @author Long (you@domain.com)
 * @brief BDN number is a number that only includes meaningful 0 or 1 digit
 * Find the number of BDN numbers less than or equal to N
 * BDN of N is P = MxN | P is BDN
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
        long long n, k;
        cin >> n;
        queue<long long> q;
        q.push(1);
        while (q.size())
        {
            k = q.front();
            if (k % n == 0)
            {
                cout << k << endl;
                break;
            }
            q.pop();
            q.push(k * 10);
            q.push(k * 10 + 1);
        }
    }
}