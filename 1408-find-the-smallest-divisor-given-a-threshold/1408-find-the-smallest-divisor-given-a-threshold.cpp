class Solution {
private:
    int sumByD(vector<int>& nums, int div) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (nums[i] + div - 1) / div; 
        }
        return sum;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = *max_element(nums.begin(), nums.end());
        
        int low = 1; 
        int high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
