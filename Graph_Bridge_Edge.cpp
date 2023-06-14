#include <bits/stdc++.h>

using namespace std;
#define V 13
vector<vector<int> > adjacent_list(V);
vector<bool> notVisited(V, true);
vector<pair<int, int> > edge;

void BFS(int n, int x, int y)
{
    queue<int> q;
    q.push(n);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : adjacent_list[u])
        {
            if ((u == x && v == y) || (u == y && v == x))
                continue;
            if (notVisited[v])
            {
                notVisited[v] = false;
                q.push(v);
            }
        }
    }
}


int main()
{
    int graph[V][V] = {{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0}};
    int countEdge{0}, stp{0}, countStp{0};
    pair<int,int> eind;

    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            if(graph[i][j])
            {
                if(i < j) 
                {
                    countEdge++;
                    eind.first = i;
                    eind.second = j;
                    edge.push_back(eind);
                }
                adjacent_list[i].push_back(j);
            }
        }
    }

    sort(edge.begin(), edge.end());

    // for(int i = 0; i < adjacent_list.size(); i++)
    // {
    //     for(int j = 0; j < adjacent_list[i].size(); j++)
    //     {
    //         cout << adjacent_list[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for(int i=0; i < edge.size(); i++)
    // {
    //     cout << edge[i].first << " " << edge[i].second << endl;
    // }

    for(int i=0; i < V; i++)
    {
        if(notVisited[i])
        {
            stp++;
            notVisited[i] = false;
            BFS(i, -1, -1);
        }
    }

    for(int i = 0; i < edge.size(); i++)
    {
        notVisited.clear();
        notVisited.resize(V+1, true);
        countStp = 0;
        for(int j = 0; j < V; j++)
        {
            if(notVisited[j])
            {
                countStp++;
                notVisited[j] = false;
                BFS(j, edge[i].first, edge[i].second);
            }
        }
        if( countStp > stp)
        {
            cout << edge[i].first << " " << edge[i].second << endl;
        }
    }
}