#include <bits/stdc++.h>

using namespace std;
#define V 13

vector<vector<int> > adjacent_list(V);
vector<bool> notVisited(V, true);

void BFS(int n)
{
    queue<int> qu;
    qu.push(n);
    int s;
    while(!qu.empty())
    {
        s = qu.front();
        qu.pop();
        for(auto v : adjacent_list[s])
        {
            if(notVisited[v])
            {
                qu.push(v);
                notVisited[v] = false;
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
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            if(graph[i][j])
            {
                adjacent_list[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < adjacent_list.size(); i++)
    {
        for(int j = 0; j < adjacent_list[i].size(); j++)
        {
            cout << adjacent_list[i][j] << " ";
        }
        cout << endl;
    }

    int stp{0}, count{0};
    for(int i=0; i<V; i++)
    {
        if(notVisited[i])
        {
            stp++;
            notVisited[i] = false;
            BFS(i);
        }
    }

    cout << "\nPillar Vertices\n";

    for(int i=0; i<V; i++)
    {
        notVisited.clear();
        notVisited.resize(V+1, true);
        count = 0;
        notVisited[i] = false;
        for(int j=0; j<V; j++)
        {
            if(notVisited[j])
            {
                count++;
                notVisited[j] = false;
                BFS(j);
            }
        }
        if(count > stp)
        {
            cout << i << " ";
        }
    }
}