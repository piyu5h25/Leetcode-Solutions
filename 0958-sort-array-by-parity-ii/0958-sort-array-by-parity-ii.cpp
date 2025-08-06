class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int e =0, o =1, n = nums.size();
        while(e< n && o <n){

            while(e<n && nums[e]%2==0){
                e = e+2;
            }
            while(o<n && nums[o]%2 ==1){
                o = o+2;
            }
            if(e<n && o<n){
                swap(nums[e], nums[o]);
            }
        }
        return nums;
    }
};