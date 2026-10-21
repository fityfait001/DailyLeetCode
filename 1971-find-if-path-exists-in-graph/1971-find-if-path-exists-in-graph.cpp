// class Solution {
// private:
//     void dfs(int source, int destination, vector<int> adj[], int vis[]) {
//         vis[source] = 1;
//         for (auto it : adj[source]) {
//             if (!vis[it]) {
//                 dfs(it, destination, adj, vis);
//             }
//         }
//     }

// public:
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         vector<int> adj[n];
        
//         // Using your exact approach for the visited array
//         int vis[n];
//         memset(vis, 0, sizeof(vis));

//         for (auto edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         dfs(source, destination, adj, vis);

//         if (vis[destination] == 1)
//             return true;
//         else
//             return false;
//     }
// };


class Solution {
private:
    void dfs(int source, int destination, vector<int> adj[], vector<int>& vis) {
        vis[source] = 1;
        for (auto it : adj[source]) {
            if (!vis[it]) {
                dfs(it, destination, adj, vis);
            }
        }
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        
        // Clean and safe: creates a vector of size n filled with 0s automatically
        vector<int> vis(n, 0);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(source, destination, adj, vis);

        if (vis[destination] == 1)
            return true;
        else
            return false;
    }
};