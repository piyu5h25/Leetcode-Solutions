class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int smaller = INT_MIN;
        int count = 0;
        int longest = 1;
        if(n==0){
            return 0;
        }
        for(int i =0; i<n;i++){
            if(nums[i]-1==smaller){
                count++;
                smaller = nums[i];
            }
            else if(smaller !=nums[i]){
                count =1;
                smaller = nums[i];
            }
            longest = max(longest,count);
        }
        return longest;
    }
};