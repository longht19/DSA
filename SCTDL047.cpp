/**
 * @file SCTDL047.cpp
 * @author Long (you@domain.com)
 * @brief Lucky number is a number that includes digits 4 & 7.
 * The author want to find the smallest lucky number that has
 * sum of all its digits equal to N
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
        int n, ok = 0;
        cin >> n;
        for (int i = 0; i <= n / 4; i++)
        {
            if ((n - i * 4) % 7 == 0)
            {
                ok = 1;
                for (int j = 0; j < i; j++)
                {
                    cout << 4;
                }
                for (int j = 0; j < (n - i * 4) / 7; j++)
                {
                    cout << 7;
                }
                cout << endl;
                break;
            }
        }
        if (ok == 0)
        {
            cout << -1 << endl;
        }
    }
}
