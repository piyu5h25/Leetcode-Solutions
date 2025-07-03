class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        int minPrices = prices[0];
        for(int i = 1;i < n;i++) {
            minPrices = min(minPrices, prices[i]);
            left[i] = max(left[i - 1], prices[i] - minPrices);
        }

        int maxProfit = prices[n - 1];
        for(int i = n - 2;i >= 0;i--) {
            maxProfit = max(maxProfit, prices[i]);
            right[i] = max(right[i + 1], maxProfit - prices[i]);
        }

        int maxP = 0;
        for(int i = 0;i < n;i++)  {
            maxP = max(maxP, left[i] + right[i]);
        }
        return maxP;
    }
};