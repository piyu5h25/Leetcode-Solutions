class Solution {
private:
    vector<int>par;
    int find_leader(int u){
        return par[u]<0?u: par[u]=find_leader(par[u]);
    }
    void merge(int u, int v){
        u = find_leader(u);
        v = find_leader(v);
        if(u==v) return;
        if(par[u]<par[v]){
            swap(u,v);
        }
        par[v]+=par[u];
        par[u]=v;
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        par.resize(n,-1);
        int cntExtra = 0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(find_leader(u)==find_leader(v)){
                cntExtra++;
            }
            else{
                merge(u,v);
            }

        }
        int noOfComponents =0;
        for(int i=0; i<n; i++){
            if(par[i]<0){
                noOfComponents++;
            }
        }
       int ans = noOfComponents-1;
       if(cntExtra>=ans)return ans;
       return -1;
        
    }
};