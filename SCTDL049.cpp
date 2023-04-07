/**
 * @file SCTDL049.cpp
 * @author long (you@domain.com)
 * @brief Binary Search
 * @version 0.1
 * @date 2023-04-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX     100000 

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        int n,k, arr[MAX];
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int result = binarySearch(arr, 0, n - 1, k);
        (result == -1)
            ? cout << "NO"
            : cout << result + 1;
        cout << endl;
    }
	return 0;
}
