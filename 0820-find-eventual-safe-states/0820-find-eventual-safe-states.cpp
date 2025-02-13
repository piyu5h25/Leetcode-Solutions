class Solution {
private:
bool dfsCheck(int node, vector<int>& vis, vector<vector<int>>& adj, vector<int>& pathVis, vector<int>& check) {
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfsCheck(it, vis, adj, pathVis, check)) {
                check[node] = 0;
                return true;
            }
        } else if (pathVis[it]) {
            check[node] = 0;
            return true;
        }
    }

    check[node] = 1;
    pathVis[node] = 0;
    return false;
}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n =adj.size();
       vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> check(n, 0);
        vector<int> safeNodes;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfsCheck(i, vis, adj, pathVis, check);
            }
        }

        for (int i = 0; i < n; i++) {
            if (check[i] == 1) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;  
    }
};