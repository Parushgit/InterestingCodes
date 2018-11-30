#include <iostream>
#include <string>
#include <vector>

using namespace std;


/**
 *
 * 

   A B C D E
A [0 1 0 0 0]
B [1 0 1 0 0]
C [0 1 0 0 0]
D [0 0 0 0 1]
E [0 0 0 1 0]

Edges:
A - B
B - C
D - E

Clusters:
A - B - C
D - E

Output:
[[A,B,C], [D,E]]

 * 
 * 
**/
// Depth first search
void dfs(vector<vector<int>> &graph, int index, vector<bool> &visited, vector<int>& output) {
    visited[index] = true;
    output.push_back(index);
    for(int i = 0; i < graph[index].size(); i++) {
        if(visited[i] == false && graph[index][i] == 1) {
            dfs(graph, i, visited, output);
        }
    }
}

/**
 * 
   A B C D E
A [0 0 1 0 1]
B [0 0 0 1 0]
C [1 0 0 0 1]
D [0 1 0 0 0]
E [1 0 1 0 0]

A C
A E
B D
C E

A C E
B D
 * 
 * 
 * 
 * 
 * 
 **/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // Data structure to store the graph
    // Assuming matrix is always valid
    
    // Test Case 1
    // vector<vector<int>> graph {{0, 1, 0, 0, 0}, {1, 0, 1, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 0, 0, 1}, {0, 0, 0, 1, 0}};
    
    // Test Case 2
    // vector<vector<int>> graph {{0, 1, 1, 1, 1}, {1, 0, 1, 1, 1}, {1, 1, 0, 1, 1}, {1, 1, 1, 0, 1}, {1, 1, 1, 1, 0}};
    
    // Test Case 3
    // vector<vector<int>> graph {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    
    // Test Case 4
    vector<vector<int>> graph {{0, 0, 1, 0, 1}, {0, 0, 0, 1, 0}, {1, 0, 0, 0, 1}, {0, 1, 0, 0, 0}, {1, 0, 1, 0, 0}};
    
    vector<int> output;
    vector<bool> visited(graph.size()); // By default this will be false
    vector<vector<int>> finalresult;
    for(int i = 0; i < graph.size(); i++) {
        if(visited[i] == false) {
            dfs(graph, i, visited, output);
            finalresult.push_back(output);
            output.clear();
        }
    }
    
    for(auto &cluster: finalresult) {
        for(int i = 0; i < cluster.size(); i++) {
            cout<<cluster[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
