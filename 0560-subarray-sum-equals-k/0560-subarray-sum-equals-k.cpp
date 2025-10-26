class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int cnt =0;
        int currSum =0;
        for(int i=0; i<nums.size(); i++){
            currSum +=nums[i];

            int requiredSum = currSum-k;
            if(mpp.count(requiredSum)){
                cnt +=mpp[requiredSum];
            }
            mpp[currSum]++;
        }
        return cnt;
    }
};