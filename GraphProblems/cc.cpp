/* This solves the BFS in an undirected graph
Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
*/
#include<iostream>
#include<stdlib.h>
#include<unordered_map>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

vector<unordered_set<int> > graph; 
void addEdge(int a, int b) {
    graph[a].insert(b);
    graph[b].insert(a);
}

void dfs(vector<unordered_set<int> >& graph, int source, vector<bool>& visited) {
    visited[source] = true;
    cout<<source<<" ";
    for(auto it = graph[source].begin(); it != graph[source].end(); it++) {
        if(visited[*it] == false)
           dfs(graph, *it, visited); 
    }
    cout<<endl;
}
void connected(vector<unordered_set<int> >& graph) {
    vector<bool> visited(graph.size(), 0);
    for(int i = 0; i < graph.size(); i++) {
        if(visited[i] == false) {
            dfs(graph, i, visited);
        }
    }
}
int main() {
    int totalNumberOfNodes = 5;
    graph.resize(totalNumberOfNodes);
    addEdge(1, 0);
    addEdge(2, 3);
    addEdge(3, 4);
    cout<<"Connected components are: "<<endl;
    connected(graph);
    return 0;
}