/**
 * @file SCTDL101.cpp
 * @author long (you@domain.com)
 * @brief DFS non-directional
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void Init_vertex_list(vector<vector<int> >* list, const int V);
void Transform_to_vertex_list(vector<vector<int> >* list, const int E);
void Sort_vertex_list(vector<vector<int> >* list, const int V);
void Display_vertex_list(vector<vector<int> >* list, const int V);
void DFS(vector<vector<int> >* list, const int V, int u);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E, u;
        vector<vector<int> > list;
        cin >> V >> E >> u;
        Init_vertex_list(&list, V);
        Transform_to_vertex_list(&list, E);
        Sort_vertex_list(&list, V);
        //Display_vertex_list(&list, V);
        DFS(&list, V, u);
        cout << endl;
        list.clear();
    }
}

void Init_vertex_list(vector<vector<int> >* list, const int V) {
    vector<int> vertex_list;
    for(int i = 0; i <= V; i++) {
        list->push_back(vertex_list);
    }
}

void Transform_to_vertex_list(vector<vector<int> >* list, const int E) {

    int vx, vy;
    for(int i = 0; i < E; i++) {
        cin >> vx >> vy;
        list->at(vx).push_back(vy);
        //list->at(vy).push_back(vx);
    }
}

void Sort_vertex_list(vector<vector<int> >* list, const int V) {
    int i;
    for( i=0; i <= V; i++) {
        sort(list->at(i).begin(), list->at(i).end());
    }
}
void Display_vertex_list(vector<vector<int> >* list, const int V) {
    int i, j;
    for( i=1; i <= V; i++) {
        cout << i << ": ";
        for( j = 0; j < list->at(i).size(); j++) {
            cout << list->at(i).at(j) << " ";
        }
        cout << endl;
    }
}

void DFS(vector<vector<int> >* list, const int V, int u) {
    bool notVisited[V+1];
    for(int i=0; i <= V; i++) {
        notVisited[i] = true;
    }
    stack<int> st;

    cout << u << " ";
    notVisited[u] = false;
    st.push(u);

    while(!st.empty()) {
        int s = st.top();
        st.pop();
        for(int i = 0; i < list->at(s).size(); i++) {
            int v = list->at(s).at(i);
            if(notVisited[v] == true) {
                cout << v << " ";
                notVisited[v] = false;
                st.push(s);
                st.push(v);
                break;
            }
        }
    }
}