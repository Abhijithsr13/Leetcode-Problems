class Solution {
    public int maximumLength(int[] nums, int k) {
         int n = nums.length;
        int maxLen = 1;

        // dp[i] stores a map: mod -> longest length of valid subsequence ending at index i
        Map<Integer, Integer>[] dp = new HashMap[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new HashMap<>();
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int mod = (nums[i] + nums[j]) % k;
                int prevLen = dp[i].getOrDefault(mod, 1);
                dp[j].put(mod, Math.max(dp[j].getOrDefault(mod, 1), prevLen + 1));
                maxLen = Math.max(maxLen, dp[j].get(mod));
            }
        }

        return maxLen;
    }
}