/***********************************************
 * Author - Abhishek
 * Roll No - B15103
 * CS 403 - Algorithm Design and Analysis
 * Assignment 1
 * Question 3
 * The Great Escape - BFS
 **********************************************/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        int vertices;
        int edges;
        vector<vector<int> > graph;

        Graph (int v, int e) {
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

        int dist_by_BFS (int source, int dest) {
            vector<int> distance(vertices, 0);
            vector<bool> visited(vertices, false);

            queue<int> main_queue;
            main_queue.push(source);

            while(!main_queue.empty()) {
                int u = main_queue.front();
                main_queue.pop();
                if(!visited[u]) {
                    visited[u] = true;
                    for(int i = 0; i < graph[u].size(); ++i) {
                        if(!visited[graph[u][i]]) {
                            main_queue.push(graph[u][i]);
                            distance[graph[u][i]] = distance[u] + 1;
                        }
                    }
                }
            }
            return distance[dest];
        }
};

int main() {
    int v, e;
    cin>>v>>e;
    Graph building_graph(v, e);
    vector<int> source(e, 0), dest(e, 0);
    for(int i = 0; i < e; ++i) {
        int u, v;
        cin>>u>>v;
        source.push_back(u-1);
        dest.push_back(v-1);
    }
    building_graph.build_edges(source, dest);
    int hero, villian;
    cin>>hero>>villian;
    hero--;
    villian--;
    cout<<building_graph.dist_by_BFS(hero, villian)<<endl;
    return 0;
}