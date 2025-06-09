class Solution {
private:
    int lcs(vector<vector<int>>& dp, int i, int j, string& text1, string& text2) {
        if (i == 0 || j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i - 1] == text2[j - 1])
            return dp[i][j] = 1 + lcs(dp, i - 1, j - 1, text1, text2);
        else
            return dp[i][j] = max(lcs(dp, i - 1, j, text1, text2), lcs(dp, i, j - 1, text1, text2));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return lcs(dp, n, m, text1, text2);
    }
};
