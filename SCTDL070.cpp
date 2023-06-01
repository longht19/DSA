/**
 * @file SCTDL070.cpp
 * @author long (you@domain.com)
 * @brief similar to knapsack problem
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
#define MAX 26
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        //set up input
        int n, w;
        cin >> w >> n;
        int value[MAX], weight[MAX], dp[n+1][w+1];
        for(int i=1; i <= n; i++) {
            cin >> weight[i];
            value[i] = weight[i];
        }
        
        // set up table to find
        memset(dp, 0, sizeof(dp));


        for(int i=1 ; i <= n; i++) {
            for(int j=1; j <= w; j++) {

                dp[i][j] = dp[i-1][j];

                if(j >= weight[i]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i]] + value[i]);
                }
            }
        }
        cout << dp[n][w] << endl;
    }
}