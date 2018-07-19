/***********************************************
 * Author - Abhishek
 * Roll No - B15103
 * CS 403 - Algorithm Design and Analysis
 * Assignment 1
 * Question 2
 * Cycle detection in an Undirected Graph
 **********************************************/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        int vertices;
        int edges;
        vector<vector<int> > graph;
        vector<bool> cycle_check_visited;

        Graph(int v, int e) {
            vertices = v;
            edges = e;
            graph.resize(v, vector<int> ());
        }

        void build_edges (vector<int> u, vector<int> v) {
            for(int i = 0; i < u.size(); ++i) {
                graph[u[i]].push_back(v[i]);
                graph[v[i]].push_back(u[i]);
            }
        }

        void print_graph() {
            for(int i = 0; i < vertices; ++i) {
                cout<<i<<" - ";
                for(int j = 0; j < graph[i].size(); ++j) {
                    cout<<graph[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        vector<int> checkForCycleRecursionHelper(int node, int parent) {
            cycle_check_visited[node] = true;
            vector<int> result;
            for(int i = 0; i < graph[node].size(); ++i) {
                if(!cycle_check_visited[graph[node][i]]) {
                    result = checkForCycleRecursionHelper(graph[node][i], node);
                    if(result.size() > 0) {
                        result.push_back(node);
                        return result;
                    }
                }
                else if(graph[node][i] != parent) {
                    result.push_back(graph[node][i]);
                    result.push_back(node);
                    return result;
                }
            }
            return result;
        }
        vector<int> checkForCycle() {
            vector<int> result;
            cycle_check_visited.resize(vertices, false);

            for(int i = 0; i < vertices; ++i) {
                if(!cycle_check_visited[i]) {
                    result = checkForCycleRecursionHelper(i, -1);
                    if (result.size() > 0) {
                        return result;
                    }
                }
            }
            return result;
        }
};

int main() {
    int v, e;
    cin>>v>>e;
    Graph main_graph(v, e);
    vector<int> source, dest;
    for(int i = 0; i < e; ++i) {
        int u, v;
        cin>>u>>v;
        source.push_back(u-1);
        dest.push_back(v-1);
    }
    main_graph.build_edges(source, dest);
    vector<int> result = main_graph.checkForCycle();
    while(result[0] != result[result.size() - 1]) {
        result.pop_back();
    }
    if (result.size() > 0) {
        cout<<"Cycle exists"<<endl;
        for(int i = 0; i < result.size(); ++i) {
            if (i != result.size() - 1){
                cout<<result[i] + 1<<"->";
            }
            else {
                cout<<result[i] + 1<<endl;
            }
        }
    }
    else {
        cout<<"No cycle"<<endl;
    }
}