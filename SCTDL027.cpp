/**
 * @file SCTDL027.cpp
 * @author your name (you@domain.com)
 * @brief program to print largest contiguous array sum
 * @version 0.1
 * @date 2023-03-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> vt, int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here = max_ending_here + vt[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}
int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> vt;
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            vt.push_back(tmp);
        }
        int max_sum = maxSubArraySum(vt, n);
	    cout << max_sum << endl;
    }
	return 0;
}
