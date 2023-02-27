/**
 * @file SCTDL005.cpp
 * @author long (you@domain.com)
 * @brief C++ program to display all permutations 
 * of an array using STL in C++
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// Function to display the array
void display(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << " ";
}

// Function to find the permutations
void findPermutations(int a[], int n)
{
    do {
        display(a, n);
    } while (next_permutation(a, a + n));
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, arr[11];
        cin >> n;
        for(int i=0; i < n; i++)    
        {
            arr[i] = i+1;
        }
        findPermutations(arr, n);
        cout << endl;
    }
    return 0;
}
