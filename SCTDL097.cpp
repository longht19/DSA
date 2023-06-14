/**
 * @file SCTDL097.cpp
 * @author long (you@domain.com)
 * @brief Postfix to Prefix
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
string operators = "+-*/^";
bool check(char c)
{
    for (int i = 0; i < operators.size(); i++)
        if (operators[i] == c)
            return 1;
    return 0;
}
bool Var(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k, ans;
        cin >> s;
        stack<string> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (Var(s[i]))
                st.push(string(1, s[i]));
            if (check(s[i]))
            {
                k = st.top();
                st.pop();
                k = s[i] + k;
                k = st.top() + k;
                st.pop();
                k = "(" + k + ")";
                st.push(k);
            }
        }
        s = st.top();
        while (!st.empty())
            st.pop();
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (Var(s[i]))
                ans = s[i] + ans;
            if (check(s[i]))
                st.push(string(1, s[i]));
            if (s[i] == '(')
            {
                ans = st.top() + ans;
                st.pop();
            }
        }
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        cout << ans << endl;
    }
}