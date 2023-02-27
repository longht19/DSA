/**
 * @file SCTDL006.cpp
 * @author long (you@domain.com)
 * @brief  C++ program to find all the number of ways, n can be 
 * written as sum of two or more positive integers.
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// Function to print the values stored
// in vector arr
void printVector(vector<int>& arr)
{
	if (arr.size() != 1) {

		// Traverse the vector arr
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

// Recursive function to print different
// ways in which N can be written as
// a sum of at 2 or more positive integers
void findWays(vector<int>& arr, int i, int n)
{
	// If n is zero then print this
	// ways of breaking numbers
	if (n == 0)
		printVector(arr);

	// Start from previous element
	// in the representation till n
	for (int j = i; j <= n; j++) {

		// Include current element
		// from representation
		arr.push_back(j);

		// Call function again
		// with reduced sum
		findWays(arr, j, n - j);

		// Backtrack to remove current
		// element from representation
		arr.pop_back();
	}
}

int main()
{
	// Given sum N
	int n = 4;

	// To store the representation
	// of breaking N
	vector<int> arr;

	// Function Call
	findWays(arr, 1, n);

	return 0;
}
