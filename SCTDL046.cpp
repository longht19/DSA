/**
 * @file SCTDL046.cpp
 * @author long (you@domain.com)
 * @brief Suppose you are a poor person in your area. 
 * Your area has only one grocery store. Your store is open 
 * every day of the week except Sunday. Given a set of three 
 * numbers N, S, and M satisfying the following constraint:
 *      N : the maximum amount of food you can buy in a day.
 *      S : number of days you need to use food to survive.
 *      M : the number of food units needed per day for you to survive. 
 * Suppose you are on the 2nd day of the week and need 
 * to survive the next S days. Specify the minimum number 
 * of days you need to buy food from the store to survive 
 * or you will starve to death in the next S days.
 * @version 0.1
 * @date 2023-03-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>


int solve(int n, int s, int m) {
    if(s*m > (s - s/7) * n) 
    {
        return -1;
    }

    for(int i=1; i <= s - s/7; i++) {
        if (n * i >= s * m)
        {
            return i;
        }
    }
}

int main() {
    int t;
    std::cin >> t;
    while(t--) { 
        int n,s,m;
        std::cin >> n >> s >> m;
        std::cout << solve(n,s,m) << std::endl;
    }
}