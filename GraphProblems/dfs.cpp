/* This solves the DFS in a directed graph
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
}

void dfs(vector<unordered_set<int> > graph, int source, vector<bool> &visited) {
    visited[source] = true;
    cout<<source<<" ";
    unordered_set<int>::iterator it;

    for(it = graph[source].begin(); it != graph[source].end(); it++) {
        if(!visited[*it]) {
            dfs(graph, *it, visited);
        }
    } 
}

int main() {
    int totalNumberOfNodes = 4;
    graph.resize(totalNumberOfNodes);
    vector<bool> visited(totalNumberOfNodes, 0);
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    cout<<"DFS Traversal is: "<<endl;
    dfs(graph, 3, visited);
    return 0;
}