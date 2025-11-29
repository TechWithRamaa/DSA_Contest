class SolutionDFS {
public:
    // TC ~ O(N); SC ~ O(N)
    int maxKDivisibleComponentsDFS(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n); // building an adjacency graph; helps for bottom-up traversal

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;
        
        dfs(0, -1, adj, values, k, ans);
        
        return ans;
    }

private:
    // post-order DFS
    // return subtree sum modulo k
    long long dfs(int u, int parent, const vector<vector<int>>& adj,
                  const vector<int>& values, int k, int &ans) {
        long long sum = values[u];
        
        for (int v : adj[u]) if (v != parent) {
            sum += dfs(v, u, adj, values, k, ans);
        }

        sum %= k;                      // keep value small
        
        if (sum == 0) 
            ++ans;          // can form a k-divisible component here
        
        return sum;
    }
};

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        // Base case: if there are less than 2 nodes, return 1
        if (n < 2) return 1;

        int componentCount = 0;
        unordered_map<int, unordered_set<int>> graph;

        // Step 1: Build the graph
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            graph[node1].insert(node2);
            graph[node2].insert(node1);
        }

        // Convert values to long long to prevent overflow
        vector<long long> longValues(values.begin(), values.end());

        // Step 2: Initialize the BFS queue with leaf nodes (nodes with only one
        // connection)
        queue<int> queue;
        for (const auto& [node, neighbors] : graph) {
            if (neighbors.size() == 1) {
                queue.push(node);
            }
        }

        // Step 3: Process nodes in BFS order
        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();

            // Find the neighbor node
            int neighborNode = -1;
            if (!graph[currentNode].empty()) {
                neighborNode = *graph[currentNode].begin();
            }

            if (neighborNode >= 0) {
                // Remove the edge between current and neighbor
                graph[neighborNode].erase(currentNode);
                graph[currentNode].erase(neighborNode);
            }

            // Check divisibility of the current node's value
            if (longValues[currentNode] % k == 0) {
                componentCount++;
            } else if (neighborNode >= 0) {
                // Add current node's value to the neighbor
                longValues[neighborNode] += longValues[currentNode];
            }

            // If the neighbor becomes a leaf node, add it to the queue
            if (neighborNode >= 0 && graph[neighborNode].size() == 1) {
                queue.push(neighborNode);
            }
        }

        return componentCount;
    }
};

