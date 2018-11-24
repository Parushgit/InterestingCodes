/* This solves the problem of finiding the shortest path in an undirected graph
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
// Unordered_map<int, vector<int> > graph; 
void addEdge(int a, int b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
}

bool BFS(int nodes, int src, int dest, vector<bool>& visited, vector<int>& dist, vector<int>& pred) {
    queue<int> q;
    visited[src] = true;
    dist[src] = 0;
    q.push(src);
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();

        for(auto it = graph[tmp].begin(); it != graph[tmp].end(); it++) {
            if(visited[*it] == false) {
                visited[*it] = true;
                dist[*it] = dist[tmp] + 1;
                pred[*it] = tmp;
                q.push(*it);

                if((*it) == dest)
                    return true;
            }
        }
    }
    return false;
}

void printTheShortestPath(int nodes, int src, int dest) {
    vector<bool> visited(nodes, 0);
    vector<int> dist(nodes, INT_MAX);
    vector<int> pred(nodes, -1);

    if(BFS(nodes, src, dest, visited, dist, pred)) {
        cout<<"Shortest distance from src to dest is: "<<dist[dest]<<endl;

        vector<int> path;
        int crawl = dest;
        path.push_back(crawl);

        while(pred[crawl] != -1) {
            path.push_back(pred[crawl]);
            crawl = pred[crawl];
        }

        cout<<"The shortest path from src to dest is: ";
        for(int i = path.size() - 1; i >= 0; i--) {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    else {
        cout<<"The path does not exist between the two vertices"<<endl;
    }

}
int main() {
    int totalNumberOfNodes = 8;
    graph.resize(totalNumberOfNodes);
    addEdge(0, 1); 
    addEdge(0, 3); 
    addEdge(1, 2); 
    addEdge(3, 4); 
    addEdge(3, 7); 
    addEdge(4, 5); 
    addEdge(4, 6); 
    addEdge(4, 7); 
    addEdge(5, 6); 
    addEdge(6, 7); 
    printTheShortestPath(totalNumberOfNodes, 2, 6);
    return 0;
}