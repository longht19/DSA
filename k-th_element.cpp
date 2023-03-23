/**
 * @file k-th_element.cpp
 * @author long (you@domain.com)
 * @brief Merge 2 arrays into one and find the k-th element
 * @version 0.1
 * @date 2023-03-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::cin, std::endl;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m,n,k;
        std::vector<int> vt1, vt2;
        cin >> m >> n >> k;

        for(int i=0; i<m; i++) {
            int tmp;
            cin >> tmp;
            vt1.push_back(tmp);
        }
        for(int i=0; i<n; i++) {
            int tmp;
            cin >> tmp;
            vt2.push_back(tmp);
        }

        std::sort(vt1.begin(), vt1.end());
        std::sort(vt2.begin(), vt2.end());

        if(vt1.size() < vt2.size()) {
            vt1.resize(vt2.size(), INT_MAX);
        } else vt2.resize(vt1.size(), INT_MAX);

        int total = m + n;
        if(k == total) {
            // cout << (vt1[m-1] < vt2[n-1]) ? vt2[n-1] : vt1[m-1];
            // cout << endl;
            if(vt1[m-1] < vt2[n-1]) {
                cout << vt2[n-1] << endl;
            } else cout << vt1[m-1] << endl;
            
        } else {
            int i{0}, j{0}, ans;
            while(total--) {
                if (k == 0) {
                    cout << ans << endl;
                    break;
                }
                if(vt1[i] < vt2[j]) {
                    ans = vt1[i];
                    k--;
                    i++;
                } else {
                    ans = vt2[j];
                    k--;
                    j++;
                }
            }
        }
    }
}