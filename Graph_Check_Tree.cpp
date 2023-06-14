#include <bits/stdc++.h>

using namespace std;

int n, E;
vector<vector<int> > adjacent;
vector<int> vertex;
bool visited[10];

void DFS(int s)
{
    stack<int> st;
    st.push(s);
    visited[s] = true;
    while(!st.empty())
    {
        int t = st.top();
        st.pop();
        for(auto v : adjacent[t])
        {
            if(!visited[v])
            {
                visited[v] = true;
                st.push(t);
                st.push(v);
                break;
            }
        }
    }
}

bool isConnected()
{
    DFS(0);

    for(int i=0; i < n; i++)
    {
        if(!visited[i])
        {
            return false;
        }
    }

    return true;
}

bool isTree()
{
    return isConnected() and E == n - 1;
}
int main()
{
    int u, v;
    cin >> n;
    for(int i =0; i < n; i++)
    {
        adjacent.push_back(vertex);
        visited[i] = false;
    }
    for(int i = 0; i < n-1; i++)
    {
        cin >> u >> v;
        E++;
        adjacent[u-1].push_back(v-1);
        adjacent[v-1].push_back(u-1);
    }
    
    if(isTree())
    {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
}