class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());

        // Lambda function to check feasibility of maxPenalty
        auto canDivide = [&](int maxPenalty) {
            int operations = 0;
            for (int num : nums) {
                // Add required splits for this bag if its size exceeds maxPenalty
                operations += (num - 1) / maxPenalty;
                // Early exit if operations exceed allowed limit
                if (operations > maxOperations) return false;
            }
            return true;
        };

        // Binary search to minimize the penalty
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDivide(mid)) {
                right = mid; // A smaller penalty might be possible
            } else {
                left = mid + 1; // Increase the penalty
            }
        }
        return left; // Minimum penalty achievable
    }
};
