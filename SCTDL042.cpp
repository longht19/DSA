/**
 * @file SCTDL042.cpp
 * @author long (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::vector<int> vta, vtb;

        std::cin >> n;
        for(int i=0; i<n; i++) {
            int tmp;
            std::cin >> tmp;
            vta.push_back(tmp);
        }
        for(int i=0; i<n; i++) {
            int tmp;
            std::cin >> tmp;
            vtb.push_back(tmp);
        }
        sort(vta.begin(), vta.end());
        sort(vtb.begin(), vtb.end());
        long long int product{0};

        for(int i=0; i<n; i++) {
            product += vta[i] * vtb[n-1-i];
        }
        std::cout << product << std::endl;
    }
}