/**
 * @file SCTDL096.cpp
 * @author long (you@domain.com)
 * @brief Prefix to infix
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string operators = "+-*/";
bool check(char c)
{
    for (int i = 0; i < operators.size(); i++)
        if (operators[i] == c)
            return 1;
    return 0;
}
bool Var(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k;
        cin >> s;
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (check(s[i]))
            {
                k = '(' + st.top();
                st.pop();
                k += s[i];
                k = k + st.top() + ')';
                st.pop();
                st.push(k);
            }
            else
                st.push(string(1, s[i]));
        }
        cout << st.top() << endl;
    }
}