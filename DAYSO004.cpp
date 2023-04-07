/**
 * @file DAYSO004.cpp
 * @author long (you@domain.com)
 * @brief the longest increase sub-array
 * @version 0.1
 * @date 2023-04-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#define MAX 100000
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, max{0}, count{1}, arr[MAX];
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int ind_prev, ind_curr;
        for(int i=0; i<n-1; i++) {
            ind_prev = i;
            for(int j = i+1; j < n; j++) {
                ind_curr = j;
                if(arr[ind_prev]  < arr[ind_curr]) {
                    count++;
                    ind_prev = ind_curr;
                } else {
                    continue;
                }
            }
            if(max < count) {
                max = count;
            }
            count = 1;
        }
        cout << max << endl;
    }
}