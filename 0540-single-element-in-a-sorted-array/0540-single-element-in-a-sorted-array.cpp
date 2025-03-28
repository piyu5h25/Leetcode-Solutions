class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-2;
        while (l  < r) {
            int m = (l + r) / 2;
            if (m % 2 == 1) {
                m--;
            }
            if (nums[m] == nums[m + 1]) {
                l = m+2;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};