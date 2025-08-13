class Solution {
public:
    bool predicate(int m, vector<int>&weights, int days){
        int cnt =1, wt = 0;
        for(int i=0; i<weights.size(); i++){
            if(wt + weights[i]<=m){
                wt +=weights[i];
            }
            else{
                wt = weights[i];
                cnt+=1;
            }
        }
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end())-1; // -1 for edge cases
        int r = accumulate(weights.begin(), weights.end(), 0)+1;// +1 for edge cases
        
        while(l+1<r){
            int m = (l + r) / 2;

            if(predicate(m, weights, days)){
                r = m;
            }
            else{
                l=m;
            }
        }
        return r;
    }
};
