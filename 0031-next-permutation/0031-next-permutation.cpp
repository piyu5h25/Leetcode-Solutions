class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        //  1 , 2 , 3 , 1    } 1 3 1  2 // 1 3 2 1

        int n = nums.size();

        int pivotidx = -1;

        for (int i = n - 2; i >= 0; i--) {

            if (nums[i] < nums[i + 1]) {
                pivotidx = i;
                // swap(nums[pivotidx], nums[i + 1]);
                break;
            }
        }
        if (pivotidx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }else{
            for(int i=n-1;i>=0;i--){
                if(nums[pivotidx] < nums[i]){
                  swap(nums[pivotidx], nums[i]);
                  break;
                }
            }
        }

        reverse(nums.begin() + pivotidx+1, nums.end());
    }
};