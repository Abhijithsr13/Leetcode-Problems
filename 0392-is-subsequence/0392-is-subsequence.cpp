class Solution {
public:
    bool isSubsequence(string s, string t) {
         int n = s.size();
        int m = t.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        for (int j = 0; j <= m; j++) {
            dp[0][j] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1]; 
                else
                    dp[i][j] = dp[i][j - 1]; 
            }
        }

        return dp[n][m];
    }
};