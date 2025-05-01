class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // vector<vector<int>>dp(n, vector<int>(n,-1));
        vector<int>next(n,0);
        for(int j=0; j<n; ++j){
            next[j]=triangle[n-1][j];
        }
        for(int i=n-2; i>=0; --i){
            vector<int>curr(n,0);
            for(int j=i; j>=0; --j){
                int down = triangle[i][j]+next[j];
                int diag = triangle[i][j]+next[j+1];
                curr[j]= min(down, diag);
            }
            next = curr;
        }
        return next[0];
    }
};