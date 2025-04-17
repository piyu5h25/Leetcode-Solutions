class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
       
        int ans = 0;
        int max_ans=0;
        for(int i=0; i<n; ++i){
            if(s[i]=='('){
                
                ans++;
                max_ans = max(ans, max_ans);
            }
            if(s[i]==')'){
               ans--;
            }
        }
        return max_ans;
    }
};