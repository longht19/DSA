/**
 * @file SCTDL040.cpp
 * @author long (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, num1{0}, num2{0};
        vector<int> vt;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            vt.push_back(tmp);
        }
        sort(vt.begin(), vt.end());
        while(vt.front() == 0) {
            vt.erase(vt.begin());
        }
        if(vt.size() == 0) {
            cout << 0 << endl;
        } else {
                for(int i=0; i<vt.size(); i+=2) {
                    num1 *= 10;
                    num1 += vt[i];
                    if(i+1 < vt.size()) {
                        num2 *= 10;
                        num2 += vt[i+1];
                    }
                }
                cout << num1 + num2 << endl;
        }
    }
}