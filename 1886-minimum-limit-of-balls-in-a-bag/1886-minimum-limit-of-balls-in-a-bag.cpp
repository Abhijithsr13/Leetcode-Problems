class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        
        // Function to check if we can achieve the maxPenalty
        auto canDivide = [&](int maxPenalty) {
            int operations = 0;
            for (int num : nums) {
                if (num > maxPenalty) {
                    // Calculate operations needed
                    operations += (num - 1) / maxPenalty;
                    // Early termination if operations exceed maxOperations
                    if (operations > maxOperations) return false;
                }
            }
            return true;
        };

        // Perform binary search for the minimum penalty
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDivide(mid)) {
                right = mid; // Try smaller penalties
            } else {
                left = mid + 1; // Increase penalty
            }
        }
        return left;
    }
};