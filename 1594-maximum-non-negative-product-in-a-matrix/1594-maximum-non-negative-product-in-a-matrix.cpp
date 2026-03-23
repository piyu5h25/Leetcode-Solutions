class Solution {
public:
    int maxProductPath(vector<vector<int>>& g) {
        int r = g.size();
        int c = g[0].size();
        long long k = 1000000007;
        vector<vector<long long>> a(r, vector<long long>(c));
        vector<vector<long long>> b(r, vector<long long>(c));
        
        a[0][0] = g[0][0];
        b[0][0] = g[0][0];
        
        for (int i = 1; i < r; ++i) {
            a[i][0] = a[i - 1][0] * g[i][0];
            b[i][0] = a[i][0];
        }
        
        for (int j = 1; j < c; ++j) {
            a[0][j] = a[0][j - 1] * g[0][j];
            b[0][j] = a[0][j];
        }
        
        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                if (g[i][j] < 0) {
                    a[i][j] = min(b[i - 1][j], b[i][j - 1]) * g[i][j];
                    b[i][j] = max(a[i - 1][j], a[i][j - 1]) * g[i][j];
                } else {
                    a[i][j] = max(a[i - 1][j], a[i][j - 1]) * g[i][j];
                    b[i][j] = min(b[i - 1][j], b[i][j - 1]) * g[i][j];
                }
            }
        }
        
        if (a[r - 1][c - 1] < 0) {
            return -1;
        }
        
        return a[r - 1][c - 1] % k;
    }
};