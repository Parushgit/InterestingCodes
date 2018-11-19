/* This solves the BFS in a directed graph
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

void bfs(vector<unordered_set<int> > graph, int source) {
    vector<bool> visited(graph.size(), 0);
    queue<int> q;

    visited[source] = true;
    q.push(source);

    unordered_set<int>::iterator it;
    while(!q.empty()) {
        source = q.front();
        cout<<source<<" ";
        q.pop();
        for(it = graph[source].begin(); it != graph[source].end(); it++) {
            if(!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}
/*
Example - 
    0
1        2
3       4
    5
*/
int main() {
    int totalNumberOfNodes = 4;
    graph.resize(totalNumberOfNodes);
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    // addEdge(4, 5);
    // addEdge(2, 4);
    cout<<"BFS Traversal is: "<<endl;
    bfs(graph, 2);
    return 0;
}