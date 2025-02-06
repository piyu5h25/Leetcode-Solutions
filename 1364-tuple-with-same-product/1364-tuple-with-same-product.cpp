class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> hash;
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {

            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];

              ans += hash[product]++;
            }
        }


        // for (auto kt : hash) {
        //     int cnt = kt.second;

        //     if (cnt > 1)
        //         ans += cnt * (cnt - 1);
        // }

        return ans * 8;
    }
};