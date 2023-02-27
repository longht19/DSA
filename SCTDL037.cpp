/**
 * @file SCTDL037.cpp
 * @author long (you@domain.com)
 * @brief C++ program to count the least money needed
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

using namespace std;
int money[] = {1,2,5,10,20,50,100,200,500,1000};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, needed{0};
        cin >> n;
        for(int i=9; i >= 0; i--)
        {
            needed += n / money[i];

            n = n % money[i];
        }
        cout << needed << endl;
    }
    return 0;
}