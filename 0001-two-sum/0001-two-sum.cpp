class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        for(int i=0; i<nums.size(); i++){
            int remTarget = target - nums[i];
            if(mpp.find(remTarget)!= mpp.end()){
                return {mpp[remTarget], i};
            }
            mpp[nums[i]]=i;
        }
        return {-1};
    }
};