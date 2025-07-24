class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
       unordered_set<int> bannedSet(banned.begin(), banned.end());
    int sum = 0, count = 0;

    for (int i = 1; i <= n; ++i) {
        // Skip banned numbers directly
        if (bannedSet.count(i)) continue;

        // Stop early if adding the current number exceeds maxSum
        if (sum + i > maxSum) break;

        sum += i;
        count++;
    }

    return count; 
    }
};