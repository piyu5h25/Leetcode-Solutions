class Solution {
    vector<int> par;

    int find_leader(int v) {
        return par[v] < 0 ? v : par[v] = find_leader(par[v]);
    }

    void merge(int u, int v) {
        u = find_leader(u);
        v = find_leader(v);
        if (u == v) return;

        if (par[u] < par[v]) swap(u, v); // par stores size as negative
        par[v] += par[u];  
        par[u] = v;        
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i=1; i<=n; i++){
            par.push_back(-1);
        }  

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (find_leader(u) == find_leader(v)) return edge; 
            merge(u, v);
        }

        return {};
    }
};
