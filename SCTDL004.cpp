/**
 * @file SCTDL004.cpp
 * @author long (you@domain.com)
 * @brief C++ program generates AB strings
 * Ideal: Generate binary strings
 * Description: 0 -> A
 *              1 -> B
 * @version 0.1
 * @date 2023-03-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
using namespace std;
#define c0   "A"
#define c1   "B"
	int t, n;

	int arr[30];

// Function to print the output
void printTheArray(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)
            cout << c0;
        else 
            cout << c1;
	}
	cout << " ";
}

// Function to generate all binary strings
void generateAllBinaryStrings(int n, int arr[], int i)
{
	if (i == n) {
		printTheArray(arr, n);
		return;
	}

	// First assign "0" at ith position
	// and try for all other permutations
	// for remaining positions
	arr[i] = 0;
	generateAllBinaryStrings(n, arr, i + 1);

	// And then assign "1" at ith position
	// and try for all other permutations
	// for remaining positions
	arr[i] = 1;
	generateAllBinaryStrings(n, arr, i + 1);
}

// Driver Code
int main()
{
	cin >> t;
    while(t--)
    {
        cin >> n;
        // Print all binary strings
        generateAllBinaryStrings(n, arr, 0);
        
        for(int i=0; i < n; i++)
        {
            arr[i] = 0;
        }
        cout << endl;
	}

	return 0;
}