/**
 * @file SCTDL030.cpp
 * @author long (you@domain.com)
 * @brief swap k times each number in a specific number
 *      to create the largest possible number
 * @version 0.1
 * @date 2023-03-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


void solve(int k, std::string s)
{
    std::vector<char> element;
    for(int i=0; i < s.size(); i++)
    {
        element.push_back(s[i]);
    }  

    std::sort(element.begin(), element.end());

    for(int i=0; i < s.size(); i++)
    {
        if(k)
        {
            if(element.back() != s[i])
            {
                char tmp = s[i];
                s[i] = element.back();
                for(int j=s.size()-1; j > i; j--)
                {
                    if(s[j] == element.back())
                    {
                        s[j] = tmp;
                        break;
                    }
                }
                element.pop_back();
                k--;
            } else {
                element.pop_back();
            }
        }
    }
    std::cout << s << std::endl;
}

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int k;
        std::string s;
        std::cin >> k >> s;
        solve(k, s);
    }
}