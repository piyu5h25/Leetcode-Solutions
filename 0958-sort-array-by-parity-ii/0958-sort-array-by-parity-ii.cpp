class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i%2 ==0 && nums[i]%2 !=0){
                for(int j = i+1; j<n; j++){
                    if(nums[j]%2 ==0){
                        swap(nums[i], nums[j]);
                    }
                }
            }
            else if(i%2 !=0 && nums[i] %2 ==0){
                for(int j = i+1; j<n; j++){
                    if(nums[j]%2 !=0){
                        swap(nums[i], nums[j]);
                    }
                }
            }
        }

        return nums;
    }
};