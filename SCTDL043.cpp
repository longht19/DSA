/**
 * @file SCTDL043.cpp
 * @author long (you@domain.com)
 * @brief Tasks sorting function
 * @version 0.1
 * @date 2023-03-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

void swap(int &x, int &y) { 
    int tmp = x;
    x = y;
    y = tmp;
}
int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n, i, j, times_beg[1001], times_end[1001];
        std::cin >> n;
        for(i = 0; i < n; i++) {
            std::cin >> times_beg[i];
        }

        for(i = 0; i < n; i++) {
            std::cin >> times_end[i];
        }

        for (i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (times_beg[j] > times_beg[j+1]) {
                    swap(times_beg[j], times_beg[j+1]);
                    swap(times_end[j], times_end[j+1]);
                } else if (times_beg[j] == times_beg[j+1]
                        && times_end[j] > times_end[j+1]) {
                    swap(times_beg[j], times_beg[j+1]);
                    swap(times_end[j], times_end[j+1]);
                }
            }
        }

        // for(i = 0; i < n; i++) {
        //     std::cout << times_beg[i] << " " << times_end[i] << std::endl;
        // }
        int ans{0}, max{0};
        for (i = 0; i < n-1; i++) {
            max = 1;
            int pre_end = times_end[i];
            for(j = i+1; j < n; j++) {
                if(times_beg[j] >= pre_end) {
                    max += 1;
                    pre_end = times_end[j];
                }
            }
            if(max > ans)   ans = max;
        }

        std::cout << ans << std::endl;
    }
}