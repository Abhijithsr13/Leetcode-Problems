class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Helper function to check if a given penalty is feasible
        auto canDivide = [&](int maxPenalty) {
            int operations = 0;
            for (int num : nums) {
                if (num > maxPenalty) {
                    // Number of operations needed to make num <= maxPenalty
                    operations += (num - 1) / maxPenalty;
                    if (operations > maxOperations) return false; // Too many operations
                }
            }
            return operations <= maxOperations;
        };

        // Binary search for the minimum possible penalty
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDivide(mid)) {
                right = mid; // Try for a smaller penalty
            } else {
                left = mid + 1; // Increase the penalty
            }
        }
        return left;
    }
};