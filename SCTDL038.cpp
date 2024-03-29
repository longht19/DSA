/**
 * @file SCTDL038.cpp
 * @author long (you@domain.com)
 * @brief  Wrong number
 *  '3' can be '5' vice versa 
 *  give A and B. find the largest and smallest
 *  sum with the condition above.
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// Wrong number
// '3' can be '5' vice versa
// give A and B. find the largest and smallest sum with the condition above.

#include <bits/stdc++.h>
#include <string>
using namespace std;

string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;
 
    // Initially take carry zero
    int carry = 0;
 
    // Traverse from end of both strings
    for (int i=n1-1; i>=0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0') + (str2[i+diff]-'0') + carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining digits of str2[]
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}

string the_smallest(string str1, string str2)
{
    for(int i=0; i < str1.size(); i++)
    {
        if(str1[i] == '5')  str1[i] = '3';
    }

    for(int i=0; i < str2.size(); i++)
    {
        if(str2[i] == '5')  str2[i] = '3';
    }

    return findSum(str1, str2);
}

string the_largest(string str1, string str2)
{
    for(int i=0; i < str1.size(); i++)
    {
        if(str1[i] == '3')  str1[i] = '5';
    }

    for(int i=0; i < str2.size(); i++)
    {
        if(str2[i] == '3')  str2[i] = '5';
    }

    return findSum(str1, str2);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        string stra, strb;
        stra = to_string(a);
        strb = to_string(b);
        cout << the_smallest(stra, strb) << " " << the_largest(stra, strb) << endl;
    }
}