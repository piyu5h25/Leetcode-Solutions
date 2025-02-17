class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256]={0};
        for (int i = 0; i < 256; i++) {
            // sabko -1 se kr diya initialise
            hash[i] = {-1};
        }
        int left = 0, right = 0;
        int n = s.size();
        int maxLen = 0;
        while (right < n) {
            if (hash[s[right]] != -1) {
                if (hash[s[right]] >= left) {
                    left = hash[s[right]] + 1;
                }
            }
            int length = right - left + 1;
            maxLen = max(length, maxLen);
            hash[s[right]]=right;
            right++;
        }
        return maxLen;
    }
};