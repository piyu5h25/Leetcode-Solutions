class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums[i]+=(1500* (nums[nums[i]]%1500));
        }
        for(int i=0; i<n; i++){
            nums[i]/=1500;
        }
        return nums;
    }

};