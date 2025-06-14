class Solution {
    int lcsSize(const string& s, const string& t, vector<vector<int>>&dp){
        int n = s.size();
        int m = t.size();
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        int lcssize = lcsSize(s, t, dp);


        
        string lcs="";
        int i = n, j = m;
        while(i > 0 && j > 0){
            if(s[i-1] == t[j-1]){
                lcs += s[i-1];
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        reverse(lcs.begin(), lcs.end());



        string ans ="";
        i=0;
        j=0;
         int k =0;
        while(i<n&& j<m && k<lcs.length()){
            if(s[i]==t[j]){
                ans+=s[i];
                i++; j++; k++;
            }
            else if( s[i]==lcs[k]){
                ans+=t[j];
                j++;
            }
            else{
                ans+=s[i];
                i++;
            }

        }
        while(i<n){
            ans+=s[i];
            i++;
        }
        while(j<m){
            ans+=t[j];
            j++;
        }
        return ans;
    }
};