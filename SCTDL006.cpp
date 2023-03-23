/**
 * @file SCTDL006.cpp
 * @author long (you@domain.com)
 * @brief C++ Program to find number of ways to 
 * which numbers that are greater than 
 * given number can be added to get sum.
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
#define MAX 100
using namespace std;

// Return number of ways to which numbers
// that are greater than given number can
// be added to get sum.
void numberofways(int n, int m)
{
	int dp[n+2][n+2];
	memset(dp, 0, sizeof(dp));

	dp[0][n + 1] = 1;

	// Filling the table. k is for numbers
	// greater than or equal that are allowed.
	for (int k = n; k >= m; k--) {

		// i is for sum
		for (int i = 0; i <= n; i++) {

			// initializing dp[i][k] to number
			// ways to get sum using numbers
			// greater than or equal k+1
			dp[i][k] = dp[i][k + 1];

			// if i > k
			if (i - k >= 0)
				dp[i][k] = (dp[i][k] + dp[i - k][k]);
		}
	}

	for(int i=0 ; i < n+2; i++)
	{
		for(int j=0 ; j < n+2 ; j++)
			cout << dp[i][j] << " ";

		cout << endl;
	}
}

int main()
{
	int n = 4, m = 1;
	numberofways(n, m);
	return 0;
}
