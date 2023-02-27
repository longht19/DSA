/**
 * @file SCTDL008.cpp
 * @author long (longzil193@gmail.com)
 * @brief Convert binary string to gray code string format.
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

using namespace std;

string bin2gray(string str)
{
    if(str.size() == 1)
        return str;
        
    string ans;
    ans.push_back(str.front());
    int msb = static_cast<int>(str.front()) - 48;
    int bi;
    char bc;
    
    for(int i=1; i < str.size(); i++)
    {
        bi = static_cast<int>(str.at(i)) - 48;
        bi = msb ^ bi;
        bc = static_cast<char>(bi + 48);
        ans.push_back(bc);
        msb = static_cast<int>(str.at(i)) - 48;
    }

    return ans;
}

int main()
{
    int t;
    string str;
    cin >> t;
    while(t--)
    {
        cin >> str;
        cout << bin2gray(str) << endl;
    }
    return 0;
}