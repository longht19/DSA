/**
 * @file SCTDL046.cpp
 * @author long (you@domain.com)
 * @brief Suppose you are a poor person in your area. 
 * Your area has only one grocery store. Your store is open 
 * every day of the week except Sunday. Given a set of three 
 * numbers N, S, and M satisfying the following constraint:
 *      N : the maximum number of food units you can buy in a day.
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
    // the amount of needed food each day is greater than or 
    // equal to the amount of maximum food you can buy in a day
    if(m > n/2) { 
        return -1;
    }

    int daysToBuyFood{0};
    int currentFood{0};
    for(int i=1; i <= s; i++) {
        // current food is less than the amount of food needed
        // to survive
        if(currentFood < m) {
            // if today is Sunday -> you starve
            if(i%7 == 0) {
                return -1;
            }

            // else you can go to the grocery store and buy food
            currentFood += n;
            daysToBuyFood += 1;
        }
        // food for today
        currentFood -= m;
    }
    return daysToBuyFood;
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