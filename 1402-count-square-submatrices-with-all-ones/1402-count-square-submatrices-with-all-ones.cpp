class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;

        // Create a DP table to store the size of the largest square ending at
        // each cell
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        // If it's in the first row or column, the size is the
                        // same as the cell value
                        dp[i][j] = 1;
                    } else {
                        // Otherwise, calculate the size of the square ending at
                        // (i, j)
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1],
                                        dp[i - 1][j - 1]}) +
                                   1;
                    }
                    count +=
                        dp[i]
                          [j]; // Add the size of the square to the total count
                }
            }
        }

        return count;
    }
};