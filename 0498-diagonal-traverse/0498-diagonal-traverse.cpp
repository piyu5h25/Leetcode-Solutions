class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        
        
        map<int, vector<int>> d;
        int n = mat.size(), m = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                d[i+j].push_back(mat[i][j]);
            }
        }
         vector<int> ans;
        for(auto & it: d){
            int diagonal = it.first;
            vector<int>val = it.second;
            if(diagonal%2==0){
                reverse(val.begin(), val.end());
            }
            ans.insert(ans.end(), val.begin(), val.end());
        }

        return ans;
    }
};