/**
 * @file SCTDL053.cpp
 * @author Long (you@domain.com)
 * @brief Counting bit 1
 * Given positive integer N.
 * Each step, N -> [N/2], N % 2, [N/2].
 * => array includes 0 & 1
 * Counting bit 1 in range [L, R] of the last number array. 
 * @version 0.1
 * @date 2023-06-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long Find(long long pos, long long n, long long ctr)
{
	if (pos & 1)
		return 1;
	if (pos == ctr)
		return (n % 2);
	if (pos > ctr)
		return Find(pos - ctr, n / 2, ctr / 2);
	return Find(pos, n / 2, ctr / 2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		long long n, l, r;
		cin >> n >> l >> r;
		long long ctr = pow(2, (long long)log2(n)), ans = 0;
		for (long long i = l; i <= r; i++)
			ans += Find(i, n, ctr);
		cout << ans << "\n";
	}
}