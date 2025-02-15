class Solution {
private: 
    void counter(int n, vector<int>& ans){
        int count =0; 
        while(n>0){
            if(n&1){
                count++;
            }
            n = n>>1;
        }
        ans.push_back(count);
    }
public:
    vector<int> countBits(int n) {
      
       vector<int> ans;
       for(int i=0;i<=n; i++){
            counter(i, ans);
       } 
       return ans;
    }
};