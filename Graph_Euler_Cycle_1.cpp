#include <bits/stdc++.h>

using namespace std;

void IsEulerian(vector<vector<int> > adjacent_list)
{
    int s, d;
    for(int i = 0; i < adjacent_list.size(); i++)
    {
        s = adjacent_list[i].size();
        if(s % 2 != 0) d++;
    }

    if(d > 2)
    {
        cout << "NO" << endl;
    } else if (d == 0)
    {
        cout << " Euler Cycle" << endl;
    } else
    {
        cout << "Euler Path" << endl;
    }
}

void Euler_Cycle(vector<vector<int> > adjacent_list, int u)
{
    stack<int> st;
    vector<int> ec;
    st.push(u);
    int s, t;
    while(!st.empty())
    {
        s = st.top();
        if(adjacent_list[s].size())
        {
            t = adjacent_list[s][0];
            st.push(t);
            adjacent_list[s].erase(adjacent_list[s].begin());
            for(int i = 0; i < adjacent_list[t].size(); i++)
            {
                if(adjacent_list[t][i] == s)
                {
                    adjacent_list[t].erase(adjacent_list[t].begin() + i);
                }
            }

        } else {
            st.pop();
            ec.push_back(s);
        }
    }

    for(int i = ec.size() - 1; i >= 0; i--)
    {
        cout << ec[i] << " ";
    }
}

void Euler_Cycle_2(int graph[13][13], int u)
{
    stack<int> st;
    vector<int> ec;
    st.push(u);
    int s, t;
    while(!st.empty())
    {
        s = st.top();
        int count = 0;
        for(int i = 0; i < 13; i++)
        {
            if(graph[s][i])
            {
                count = 1;
                t = i;
                break;
            }
        }
        if(count)
        {
            st.push(t);
            graph[s][t] = 0;
            graph[t][s] = 0;
        } else
        {
            st.pop();
            ec.push_back(s);
        }
    }

    for(int i = ec.size() - 1; i >= 0; i--)
    {
        cout << ec[i] << " ";
    }
}


int main()
{
    int graph[13][13] = {{0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0},
                        {0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                        {1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0},
                        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1},
                        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                        {0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
                        {0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
                        {0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0}};
    vector<vector<int> > adjacent_list(13);
    for(int i=0; i<13; i++)
    {
        for(int j=0; j<13; j++)
        {
            if(graph[i][j])
            {
                adjacent_list[i].push_back(j);
            }
        }
    }
    for(int i=0; i<adjacent_list.size(); i++)
    {
        sort(adjacent_list[i].begin(), adjacent_list[i].end());
    }

    for(int i = 0; i < adjacent_list.size(); i++)
    {
        for(int j = 0; j < adjacent_list[i].size(); j++)
        {
            cout << adjacent_list[i][j] << " ";
        }
        cout << endl;
    }
    
    IsEulerian(adjacent_list);
    Euler_Cycle(adjacent_list, 0);
    //Euler_Cycle_2(graph, 0);
}