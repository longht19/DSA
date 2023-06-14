#include <bits/stdc++.h>

using namespace std;
const string ops = "+-*/^";

bool check_ops(char c)
{
    for(int i = 0; i < ops.size(); i++)
    {
        if(c == ops[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    string test = "ab+cd-*", k;
    stack<string> st;
    for(int i=0; i < test.length(); i++)
    {
        if(!check_ops(test[i]))
        {
            st.push(string(1, test[i]));
        } else
        {
            k = st.top();
            st.pop();
            k = st.top() + k;
            st.pop();
            k = test[i] + k;
            st.push(k);
        }
    }
    cout << st.top() << endl;
}