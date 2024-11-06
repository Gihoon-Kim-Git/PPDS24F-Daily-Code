#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

// Problem Summary:
// We are given a bi-directional graph with `n` vertices labeled from 0 to n - 1.
// The graph's edges are given as a 2D integer array `edges`,
// where each edge connects two vertices `u_i` and `v_i`. edges[i] = [u_i, v_i]
// The goal is to determine if there is a valid path from vertex `source` to vertex `destination`.

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // If the source and destination are the same, a path trivially exists
        if (source == destination) {
            return true;
        }

        // Step 1: Build the adjacency list to represent the graph
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; ++i) {
            graph[i] = vector<int>();
        }
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Step 2: Perform a Breadth-First Search (BFS) to check for a valid path
        unordered_set<int> visited; // To keep track of visited nodes
        queue<int> queue;           // Initialize the queue with the source vertex
        queue.push(source);

        while (!queue.empty()) {
            int curr = queue.front();
            queue.pop();

            // If we reach the destination, return true
            if (curr == destination) {
                return true;
            }

            visited.insert(curr); // Mark the current node as visited

            // Iterate over all the neighbors of the current node
            for (const int& neighbor : graph[curr]) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.push(neighbor); // Add unvisited neighbors to the queue
                }
            }
        }

        // If we exhaust all possible paths and do not reach the destination, return false
        return false;
    }
};

// Main function to test the validPath function
int main() {
    Solution solution;

    // Example 1: Should return true
    int n1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    int source1 = 0;
    int destination1 = 2;
    cout << boolalpha << solution.validPath(n1, edges1, source1, destination1) << endl; // Output: true

    // Example 2: Should return false
    int n2 = 6;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    int source2 = 0;
    int destination2 = 5;
    cout << boolalpha << solution.validPath(n2, edges2, source2, destination2) << endl; // Output: false

    // Additional Test Case 1: Should return true
    int n3 = 5;
    vector<vector<int>> edges3 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    int source3 = 0;
    int destination3 = 4;
    cout << boolalpha << solution.validPath(n3, edges3, source3, destination3) << endl; // Output: true

    // Additional Test Case 2: Should return true
    int n4 = 7;
    vector<vector<int>> edges4 = {{0, 6}, {6, 5}, {5, 4}, {4, 3}, {3, 2}, {2, 1}, {1, 0}};
    int source4 = 0;
    int destination4 = 3;
    cout << boolalpha << solution.validPath(n4, edges4, source4, destination4) << endl; // Output: true

    return 0;
}
/*
0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week09 (main)
$ g++ validpath_graph.cpp -o vpathg

0806a@LAPTOP-SAGEKIM MINGW64 ~/Desktop/Lecture/SNUGSDS/ProgrammingPractice/PPDS24F-Daily-Code/week09 (main)
$ ./vpathg
true
false
true
true
*/

// LEETCODE: TIME LIMIT EXCEEDED ERROR!