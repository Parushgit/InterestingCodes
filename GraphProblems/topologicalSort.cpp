/* This solves the problem of finiding topological sort in a directed graph
Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
https://www.geeksforgeeks.org/topological-sorting/
*/
#include<iostream>
#include<stdlib.h>
#include<unordered_map>
#include<vector>
#include<queue>
#include<unordered_set>
#include<stack>

using namespace std;

// Adjacency matrix
vector<vector<int> > graph;
// Unordered_map<int, vector<int> > graph; 
void addEdge(int a, int b) {
    graph[a].push_back(b);
}

void dfs(vector<bool>& visited, int src, stack<int>& st) {
    visited[src] = true;

    for(auto it = graph[src].begin(); it != graph[src].end(); it++) {
        if(visited[*it] == false)
            dfs(visited, *it, st);
    }
    st.push(src);
}

void topologicalSort(int nodes) {
    vector<bool> visited(nodes, 0);

    stack<int> st;
    for(int i = 0; i < nodes; i++) {
        if(visited[i] == false) {
            dfs(visited, i, st);
        }
    }

    cout<<"Toplogical sort is as follows: ";

    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main() {
    int totalNumberOfNodes = 6;
    graph.resize(totalNumberOfNodes);
    // addEdge(0, 1); 
    // addEdge(0, 3); 
    // addEdge(1, 2); 
    // addEdge(3, 4); 
    // addEdge(3, 7); 
    // addEdge(4, 5); 
    // addEdge(4, 6); 
    // addEdge(4, 7); 
    // addEdge(5, 6); 
    // addEdge(6, 7); 
    addEdge(5, 2); 
    addEdge(5, 0); 
    addEdge(4, 0); 
    addEdge(4, 1); 
    addEdge(2, 3); 
    addEdge(3, 1);
    topologicalSort(totalNumberOfNodes);
    return 0;
}