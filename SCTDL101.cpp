/**
 * @file SCTDL101.cpp
 * @author long (you@domain.com)
 * @brief Transform edge list to adjacent list
 * @version 0.1
 * @date 2023-04-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Init_vertex_list(vector<vector<int> >* list, const int V);
void Transform_to_vertex_list(vector<vector<int> >* list, const int E);
void Display_vertex_list(vector<vector<int> >* list, const int V);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        vector<vector<int> > list;
        cin >> V >> E;
        Init_vertex_list(&list, V);
        Transform_to_vertex_list(&list, E);
        Display_vertex_list(&list, V);
    }
}

void Init_vertex_list(vector<vector<int> >* list, const int V) {
    vector<int> vertex_list;
    for(int i = 0; i < V; i++) {
        list->push_back(vertex_list);
    }
}

void Transform_to_vertex_list(vector<vector<int> >* list, const int E) {

    int vx, vy;
    for(int i = 0; i < E; i++) {
        cin >> vx >> vy;
        list->at(vx-1).push_back(vy);
        list->at(vy-1).push_back(vx);
    }
}

void Display_vertex_list(vector<vector<int> >* list, const int V) {
    int i, j;
    for( i=0; i < V; i++) {
        sort(list->at(i).begin(), list->at(i).end());
    }
    for( i=0; i < V; i++) {
        cout << i+1 << ": ";
        for( j = 0; j < list->at(i).size(); j++) {
            cout << list->at(i).at(j) << " ";
        }
        cout << endl;
    }
    list->clear();
}