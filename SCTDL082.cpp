/**
 * @file SCTDL082.cpp
 * @author long (you@domain.com)
 * @brief Reverse stack using recursion algorithm
 * @version 0.1
 * @date 2023-04-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int>& st, int x)
{

	if (st.size() == 0) {
		st.push(x);
	}
	else {
		int a = st.top();
		st.pop();
		insert_at_bottom(st, x);
		st.push(a);
	}
}

void reverse(stack<int>& st)
{
	if (st.size() > 0) {
		int x = st.top();
		st.pop();
		reverse(st);
		insert_at_bottom(st, x);
	}
	return;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        stack<int> st, st2;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            st.push(tmp);
        }
        st2 = st;
        while (!st2.empty()) {
            cout << st2.top() << " ";
            st2.pop();
        }
        cout<<endl;
        reverse(st);
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
	return 0;
}
