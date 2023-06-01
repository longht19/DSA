/**
 * @file SCTDL022.cpp
 * @author long (you@domain.com)
 * @brief C++ program counting of ways in which N can be 
 * represented as sum of Fibonacci numbers without repetition
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
using namespace std;

long long fib[101], dp1[101];
long long dp2[101], v[101];

// Function to generate the
// fibonacci number
void fibonacci()
{
	// First two number of
	// fibonacci sequence
	fib[1] = 1;
	fib[2] = 2;

	for (int i = 3; i <= 87; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
}

// Function to find maximum ways to
// represent num as the sum of
// fibonacci number
int find(int num)
{
	int cnt = 0;

	// Generate the Canonical form
	// of given number
	for (int i = 87; i > 0; i--) {
		if (num >= fib[i]) {
			v[cnt++] = i;
			num -= fib[i];
		}
	}

	// Reverse the number
	reverse(v, v + cnt);

	// Base condition of dp1 and dp2
	dp1[0] = 1;
	dp2[0] = (v[0] - 1) / 2;

	// Iterate from 1 to cnt
	for (int i = 1; i < cnt; i++) {

		// Calculate dp1[]
		dp1[i] = dp1[i - 1] + dp2[i - 1];

		// Calculate dp2[]
		dp2[i] = ((v[i] - v[i - 1]) / 2) * dp2[i - 1] + ((v[i] - v[i - 1] - 1) / 2)	* dp1[i - 1];
	}

	// Return final ans
	return (dp1[cnt - 1] + dp2[cnt - 1]);
}

int main()
{
	// Function call to generate the
	// fibonacci numbers
	fibonacci();
    int t;
    cin >> t;
    while(t--) {
        int num;
        // Given Number
        cin >> num;
        // Function Call
        cout << find(num) << endl;
    }
	return 0;
}