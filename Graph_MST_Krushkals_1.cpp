#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define V 13
#define endl "\n"

using namespace std;

const int MAX = 1000;
int parent[MAX], countEdgex{0};
pair <long long, pair<int, int> > p[MAX];
vector<pair<int, pair<int, int> > > mst;

int graph[V][V] = { {0, 2, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {2, 0, 2, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0},
                    {1, 2, 0, 4, 0, 5, 0, 0, 0, 0, 0, 0, 0},
                    {3, 0, 4, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 5, 0, 6, 0, 0, 0, 6, 0, 0, 0},
                    {0, 5, 5, 5, 6, 0, 6, 6, 6, 6, 0, 0, 0},
                    {0, 5, 0, 0, 0, 6, 0, 6, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 6, 6, 0, 7, 0, 0, 7, 7},
                    {0, 0, 0, 0, 0, 6, 0, 7, 0, 7, 7, 0, 0},
                    {0, 0, 0, 0, 6, 6, 0, 0, 7, 0, 7, 7, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 0, 8, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 0, 7, 8, 0, 8},
                    {0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 8, 0}};
void Init()
{
    for(int i = 0;i < V;++i)
        parent[i] = i;
}

int Find(int x)
{
    while(parent[x] != x)
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void Union(int x, int y)
{
    int p = Find(x);
    int q = Find(y);
    parent[p] = parent[q];
}

long long Krushkals(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < countEdgex;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(Find(x) != Find(y))
        {
            minimumCost += cost;
            mst.push_back(make_pair(cost, make_pair(x, y)));
            Union(x, y);
        }    
    }
    return minimumCost;
}

int main()
{
    Init();
    for(int i=0; i < V; i++)
    {
        for(int j=0; j < V; j++)
        {
            if(graph[i][j] && i < j)
            {
                p[countEdgex++] = make_pair(graph[i][j], make_pair(i, j));
            }
        }
    }
    // Sort the edges in the ascending order
    sort(p, p + countEdgex);
    cout << Krushkals(p) << endl;
    for(int i=0; i < mst.size(); i++) {
        cout    << mst[i].second.first << " - " 
                << mst[i].second.second << " : " 
                << mst[i].first << endl;
    }
    return 0;
}