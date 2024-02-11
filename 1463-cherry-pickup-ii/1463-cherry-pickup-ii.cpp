class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
    int cols = grid[0].size();
    
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));

    function<int(int, int, int)> dfs = [&](int row, int col1, int col2) -> int {
        if (row == rows)
            return 0;
        
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int cherries = 0;

        for (int move1 = -1; move1 <= 1; ++move1) {
            for (int move2 = -1; move2 <= 1; ++move2) {
                int newCol1 = col1 + move1;
                int newCol2 = col2 + move2;

                if (newCol1 >= 0 && newCol1 < cols && newCol2 >= 0 && newCol2 < cols) {
                    cherries = max(cherries, dfs(row + 1, newCol1, newCol2));
                }
            }
        }

        int currentCherries = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];
        cherries += currentCherries;

        dp[row][col1][col2] = cherries;
        return cherries;
    };

    return dfs(0, 0, cols - 1);

    }
};