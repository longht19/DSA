// C++ program to find a triplet
#include <bits/stdc++.h>
using namespace std;
#define MAX 2501

int find3Numbers(int A[], int arr_size, int sum)
{
	int l, r, count{0};
	/* Now fix the first element one by one and find the
	other two elements */
	for (int i = 0; i <= arr_size - 2; i++) {

		// To find the other two elements, start two index
		// variables from two corners of the array and move
		// them toward each other
		l = i + 1; // index of the first element in the
		// remaining elements
		r = arr_size - 1; // index of the last element
		while (l < r) {
			if (A[i] + A[l] + A[r] == sum) {
				count++;
			}
			else if (A[i] + A[l] + A[r] < sum) {
				l++;
            }
			else {
				r--;
            }
		}
	}
	return count;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int k, s, arr[MAX];
        cin >> k >> s;
        for(int i=0; i <= k; i++) {
            arr[i] = i;
        }
        cout << find3Numbers(arr, k+1, s) << endl;
    }
}

