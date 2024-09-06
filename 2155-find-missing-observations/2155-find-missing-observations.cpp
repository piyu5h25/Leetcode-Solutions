class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        // Step 1: Calculate the total sum of (n + m) rolls
        int m = rolls.size();
        int totalSum = mean * (n + m);
        
        // Step 2: Calculate the sum of the known rolls
        int knownSum = accumulate(rolls.begin(), rolls.end(), 0);
        
        // Step 3: Calculate the sum of the missing rolls
        int missingSum = totalSum - knownSum;
        
        // Step 4: Check if the missing sum is valid (each roll should be between 1 and 6)
        if (missingSum < n || missingSum > 6 * n) {
            return {};  // If it's not possible, return an empty array
        }
        
        // Step 5: Distribute the missingSum across n rolls
        vector<int> result(n, 1);  // Start by giving each missing roll a value of 1
        missingSum -= n;  // Subtract the initial 1s already distributed
        
        for (int i = 0; i < n && missingSum > 0; ++i) {
            // Give as much as possible to each roll without exceeding 6
            int add = min(5, missingSum);
            result[i] += add;
            missingSum -= add;
        }
        
        return result;
    }
};