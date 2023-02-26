/**
 * @file SCTDL010.cpp
 * @author long (longzil193@gmail.com)
 * @brief C++ file representation binary strings have number of 0s
 * equal to the number of 1s
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// Recursive function that prints
// all strings of N length with equal 1's and 0's
void binaryNum(int n, string s, int ones, int zeros)
{

	// String s contains the output to be printed
	// ones stores the frequency of 1's
	// zeros stores the frequency of 0's
	// Base Condition: When the length of string s
	// becomes N
	if (s.length() == n)
	{
		cout << (s) << " ";
		return;
	}
    // If frequency of 0's is less than N/2 then
	// add 0 to the string and increment zeros
	if (zeros < n / 2)
		binaryNum(n, s + "0", ones, zeros + 1);

	// If frequency of 1's is less than N/2 then
	// add 1 to the string and increment ones
	if (ones < n / 2)
		binaryNum(n, s + "1", ones + 1, zeros);
}

int main()
{
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;
        string s = "";
        if(!(n&1))
            binaryNum(n, s, 0, 0);
        else 
            cout << -1 << endl;

        cout << endl;
    }
    return 0;
}

