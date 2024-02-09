class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort for efficient comparisons

        // Initialize DP and parent arrays
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        // Find the longest divisible subset
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }

        // Backtrack to find the actual elements
        int max_index = 0;
        for (int i = 1; i < n; i++) {
            if (dp[i] > dp[max_index]) {
                max_index = i;
            }
        }

        vector<int> ans;
        while (max_index != -1) {
            ans.push_back(nums[max_index]);
            max_index = parent[max_index];
        }

        reverse(ans.begin(), ans.end()); // Reverse to get the correct order
        return ans;
    }
};