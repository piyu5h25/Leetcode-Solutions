class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            return {}; // Return an empty array if not possible
        }

        // Initialize the 2D array
        vector<vector<int>> result(m, vector<int>(n));

        // Fill in the 2D array using elements from the original array
        for (int i = 0; i < original.size(); ++i) {
            int row = i / n; // Calculate the row index
            int col = i % n; // Calculate the column index
            result[row][col] = original[i];
        }

        return result;
    }
};