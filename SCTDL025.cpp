/**
 * @file SCTDL025.cpp
 * @author long (you@domain.com)
 * @brief consecutive sub array that has largest sum
 *       Kadane's algorithm
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
#include<climits>
using namespace std;

#define MAX 10000000
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, arr[MAX];
        cin >> n;
        for(int i = 0; i< n; i++) cin >> arr[i];

        int max_so_far = INT_MIN;
        int max_ending_here = 0;

        for(int i=0; i<n; i++){
            max_ending_here += arr[i];
            if(max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
            }
            if(max_ending_here < 0) {
                max_ending_here = 0;
            }
        }
        cout << max_so_far << endl;
    }
}