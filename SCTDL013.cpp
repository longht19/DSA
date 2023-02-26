/**
 * @file SCTDL013.cpp
 * @author long (longzil193@gmail.com)
 * @brief C++ implementation of generating nCk of the number N
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>

using namespace std;
int t, k, n, X[15];
bool check = true;

void Result()
{
    for (int i = 1; i <= k; i++)
    {
        cout << X[i];
    }
    cout << " ";
}

void combination(int n, int k)
{
    int i = k;
    while(i > 0 && X[i] == n-k+i) 
        i--;

    if(i > 0)
    {
        X[i] = X[i] + 1;
        for(int j = i+1; j <= k; j++)
        {
            X[j] = X[i] + j - i;
        }
    }
    else check = false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for(int i=1; i <= k; i++)
        {
            X[i] = i;
        }
        while(check)
        {
            Result();
            combination(n, k);
        }
        check = true;
        cout << endl;
    }
    return 0;
}