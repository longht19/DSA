/**
 * @file SCTDL083.cpp
 * @author long (you@domain.com)
 * @brief Reverse ordering of the first k elements of array
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void reverseQueueFirstKElements(int k, queue<int>& Queue) 
{
    if (Queue.empty() == true || k > Queue.size())
        return;
    if (k <= 0)
        return;
 
    stack<int> Stack;

    for(int i=0; i < k; i++) {
        Stack.push(Queue.front());
        Queue.pop();
    }

    while(!Stack.empty()) 
    {
        Queue.push(Stack.top());
        Stack.pop();
    }

    for(int i=0; i < Queue.size()-k; i++)
    {
        Queue.push(Queue.front());
        Queue.pop();
    }
}

void Print(queue<int>& Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        queue<int> queue;
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            queue.push(tmp);
        }
        reverseQueueFirstKElements(k, queue);
        Print(queue);
    }
	return 0;
}