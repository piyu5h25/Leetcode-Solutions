class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return -1;
        }
        if(n==1 && m==1)return 1;
        vector<vector<int>>dist(n,vector<int>(m, INT_MAX));
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto it  = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    if(i==0 && j==0){
                        continue;
                    }
                    int nr = row+i;
                    int nc = col+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && dis+1<dist[nr][nc]){
                        dist[nr][nc]=dis+1;
                        if(nr == n-1 && nc == m-1)return dis+1;
                        q.push({1+dis,{nr, nc}});
                    }
                }
            }
        }
        return -1;
        
    }
};