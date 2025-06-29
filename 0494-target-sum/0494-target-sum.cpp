class Solution {
private:
    int findWays(vector<int>& num, int tar){
        int n = num.size();
        vector<int> prev(tar + 1, 0), cur(tar + 1, 0);

        if (num[0] == 0) 
            prev[0] = 2;  // Two ways: pick or not pick zero
        else 
            prev[0] = 1;  // Only not pick

        if (num[0] != 0 && num[0] <= tar) 
            prev[num[0]] = 1; // Pick first element if it fits

        for (int ind = 1; ind < n; ind++) {
            for (int sum = 0; sum <= tar; sum++) {
                int notTake = prev[sum];
                int take = 0;
                if (num[ind] <= sum) 
                    take = prev[sum - num[ind]];
                cur[sum] = notTake + take;
            }
            prev = cur;
        }
        return prev[tar];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums) 
            totalSum += num;

        // Check validity
        if (totalSum < abs(target) || (totalSum - target) % 2 != 0) 
            return 0;

        int s2 = (totalSum - target) / 2;
        return findWays(nums, s2);
    }
};
