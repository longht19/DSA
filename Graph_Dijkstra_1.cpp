#include <bits/stdc++.h>

using namespace std;
#define V 9
int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
int front[V], d[V];
bool final[V];
void Dijkstra(int s, int t)
{
    int u,v, min;
    front[s] = -1;
    d[s] = 0;
    final[s] = true;
    for(int i=0; i < V; i++)
    {
        front[i] = s;
        final[i] = false;
        if(graph[s][i])
        {
            d[i] = graph[s][i];
        } else d[i] = INT_MAX;
    }
    final[s] = true;

    while(!final[t])
    {
        min = INT_MAX;
        for(int i=0; i < V; i++)
        {
            if(!final[i] && d[i] < min)
            {
                u = i;
                min = d[i];
            }
        }
        final[u] = true;
        if(!final[t])
        {
            for(int i=0; i < V; i++)
            {
                if(!final[i] && d[u] + graph[u][i] < d[i])
                {
                    d[i] = d[u] + graph[u][i];
                    front[i] = u;
                }
            }
        }
    }
}

void Result(int s, int t)
{
    int i = front[t];
    while(i != s)
    {
        cout << i << " ";
        i = front[i];
    }
    cout << endl << d[t] << endl;
}

int main()
{
    int s, t;
    cin >> s >> t;
    Dijkstra(s, t);
    Result(s, t);
}