/**
 * @file findingMax.cpp
 * @author long (you@domain.com)
 * @brief find max answer
 *        
 * @version 0.1
 * @date 2023-03-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::cin, std::vector;

const long long MODULO = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        long long ans;
        vector<long long> vt;
        cin >> n;
        for(int i=0; i<n; i++) {
            int tmp;
            cin >> tmp;
            vt.push_back(tmp);
        }
        sort(vt.begin(), vt.end());

        for(int i=0; i < n; i++) {
            ans += (vt[i] * i);
            ans = ans % MODULO;
        }
        ans = ans % MODULO;
        cout << ans << std::endl;
    }    
}