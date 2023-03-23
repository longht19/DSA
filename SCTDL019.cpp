/**
 * @file SCTDL019.cpp
 * @author long (longzil193@gmail.com)
 * @brief The next permutation
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 103 

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, arr[MAX];
        cin >> n;
        for(int i=0; i < n; i++)
        {
            cin >> arr[i];
        }

        if(next_permutation(arr, arr+n))
        {
            for(int i=0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
        } else
        {
            for(int i=0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << "\n";
    }    
}