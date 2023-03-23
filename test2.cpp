/**
 * @file fiboString.cpp
 * @author long (you@domain.com)
 * @brief  
    G(1) = A,
    G(2) = B,
    G(n) = G(n-2) + G(n-1)
    '+': connect two string

    find i-th character of n-th fibonacci string
 * @version 0.1
 * @date 2023-03-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

string fibWord(int n)
{
	string str_prev = "A";
	string str_curr = "B";
	string tmp;
	for (int i=3; i<=n; i++)
	{
		tmp = str_curr;
		str_curr = str_prev + str_curr;
		str_prev = tmp;
	}

	return str_curr;
}

int main()
{
	int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        string res = fibWord(n);
        cout << res[i-1] << endl;
    }
	return 0;
}
