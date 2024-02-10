class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
    int n = s.length();

    // Create a 2D array to store whether a substring is a palindrome or not
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        count++;
    }

    // Check substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            count++;
        }
    }

    // Check substrings of length 3 or more
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            // Check if the current substring is a palindrome
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;
                count++;
            }
        }
    }

    return count;
    }
};