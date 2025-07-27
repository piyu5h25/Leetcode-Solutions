class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        int l = 0, r = n - 1;

        while (l <= r) {
            if (abs(arr[l]) > abs(arr[r])) {
                ans.push_back(arr[l] * arr[l]);
                l++;
            } else {
                ans.push_back(arr[r] * arr[r]);
                r--;
            }
        }

        reverse(ans.begin(), ans.end()); 
        return ans;
    }
};
