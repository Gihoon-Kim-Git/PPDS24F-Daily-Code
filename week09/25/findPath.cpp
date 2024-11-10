#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Step 1: Build the graph as an adjacency list
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Step 2: Initialize a queue for BFS and a visited set to prevent revisiting nodes
        queue<int> q;
        unordered_set<int> visited;
        
        
        // Start the BFS from the source node
        q.push(source);
        visited.insert(source);
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            // Check if we have reached the destination
            if (current == destination) {
                return true;
            }
            
            // Explore all neighbors of the current node
            for (int neighbor : graph[current]) {
                if (visited.find(neighbor) == visited.end()) { // Not visited
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        
        // If BFS completes without finding the destination
        return false;
    }
};

int main(void) {

    return 0;
}