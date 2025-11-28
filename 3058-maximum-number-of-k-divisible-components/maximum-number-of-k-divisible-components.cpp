class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        dfs(0, -1, adj, values, k, ans);
        return ans;
    }

private:
    // return subtree sum modulo k
    long long dfs(int u, int parent, const vector<vector<int>>& adj,
                  const vector<int>& values, int k, int &ans) {
        long long sum = values[u];
        for (int v : adj[u]) if (v != parent) {
            sum += dfs(v, u, adj, values, k, ans);
        }
        sum %= k;                      // keep value small
        if (sum == 0) ++ans;          // can form a k-divisible component here
        return sum;
    }
};