/**
 * @file SCTDl020.cpp
 * @author long (you@domain.com)
 * @brief C++ program to count number of ways any
 * given integer x can be expressed as n-th
 * power of unique natural numbers
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// Function to calculate and return the
// power of any given number
int power(int num, unsigned int n)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return power(num, n / 2) * power(num, n / 2);
	else
		return num * power(num, n / 2) * power(num, n / 2);
}

// Function to check power representations recursively
int checkRecursive(int x, int n, int curr_num = 1,
				int curr_sum = 0)
{
	// Initialize number of ways to express
	// x as n-th powers of different natural
	// numbers
	int results = 0;

	// Calling power of 'i' raised to 'n'
	int p = power(curr_num, n);
	while (p + curr_sum < x) {
		// Recursively check all greater values of i
		results += checkRecursive(x, n, curr_num + 1, p + curr_sum);
		curr_num++;
		p = power(curr_num, n);
	}

	// If sum of powers is equal to x
	// then increase the value of result.
	if (p + curr_sum == x)
		results++;

	// Return the final result
	return results;
}

int main()
{
	int t;
    cin >> t;
    while (t--) {
        int m,n;
        cin >> m >> n;
        cout << checkRecursive(m, n) << endl;
    }
	return 0;
}
