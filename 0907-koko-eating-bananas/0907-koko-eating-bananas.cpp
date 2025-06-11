class Solution {
private:
    int predicate(vector<int>&arr, int h, int k){
        long long cnt =0;
        for(int i=0; i<arr.size(); i++){
            cnt+= ceil((double)arr[i]/k);

        }
        if(cnt<=h){
            return 1;
        }
        else{
           return 0;
        }
        

    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 0;
        int r = *max_element(piles.begin(), piles.end())+1;
        while(l+1<r){
            int m = (l+r)/2;
            if(predicate(piles, h, m)==0){
                l = m;
            }
            else{
                r = m;
            }
        }
        return r;
    }
};