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
vector<vector<int>> vt;
vector<int> permutation;
// Function to find the permutations
void findPermutations(int a[], int n)
{

    do {
        for(int i=0; i < n; i++)
        {
            permutation.push_back(a[i]);
        }
        vt.push_back(permutation);
        permutation.clear();
    } while (next_permutation(a, a + n));
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, arr[10000];
        cin >> n;
        for(int i=0; i < n; i++)    
        {
            arr[i] = i+1;
        }
        findPermutations(arr, n);
        for(int i=vt.size()-1; i >= 0; i--)
        {
            for(int j=0; j < n; j++)
                cout << vt[i][j];

            cout << " ";
        }
        vt.clear();
        cout << endl;
    }
    return 0;
}
