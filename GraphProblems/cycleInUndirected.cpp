/* This solves to detect cycle in an undirected graph
Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
*/
#include<iostream>
#include<stdlib.h>
#include<unordered_map>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

// Adjacency matrix
vector<vector<int> > graph;
//unordered_map<int, vector<int> > graph; 
void addEdge(int a, int b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
}

bool dfs(int source, vector<bool>& visited, int parent) {
    visited[source] = true;
    vector<int>::iterator it;
    for(it = graph[source].begin(); it != graph[source].end(); it++) {
        // If not visited then visit
        if(visited[*it] == false) {
            if(dfs(*it, visited, source))
                return true;
        }
        // If there is an adjacent ‘u’ such that u is already visited and u is not parent of v, then there is a cycle in graph
        else if(*it != parent)
            return true; 
    }
    return false;
}
bool cycle(vector<vector<int> >& graph) {
    vector<bool> visited(graph.size(), 0);
    for(int i = 0; i < graph.size(); i++) {
        if(visited[i] == false) {
            if(dfs(i, visited, -1))
                return true;
        }
    }
    return false;
}
int main() {
    int totalNumberOfNodes = 3;
    graph.resize(totalNumberOfNodes);
    addEdge(1, 0);
    addEdge(0, 2);
    // addEdge(2, 0);
    // addEdge(0, 3);
    // addEdge(3, 4);
    bool result = cycle(graph);
    cout<<"Is cycle there: "<<result<<endl;
    return 0;
}