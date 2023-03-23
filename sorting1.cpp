/**
 * @file sorting1.cpp
 * @author long (you@domain.com)
 * @brief sorting 1
 * @version 0.1
 * @date 2023-03-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, arr[1001];
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        
        std::sort(arr, arr + n);
        // for(int i=0; i < n; i++) {
        //     std::cout << arr[i] << " ";
        // }
        int head{0}, tail{n-1};
        while(head < n/2) {
            std::cout << arr[tail--] << " ";
            std::cout << arr[head++] << " ";
        }
        if(n%2!=0) {
            std::cout << arr[head];
        }
        std::cout << std::endl;
    }
}