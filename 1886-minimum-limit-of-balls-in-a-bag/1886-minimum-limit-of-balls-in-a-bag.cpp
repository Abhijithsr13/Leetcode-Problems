class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        
        // Lambda function to check feasibility of maxPenalty
        auto canDivide = [&](int maxPenalty) {
            int operations = 0;
            for (int num : nums) {
                operations += (num - 1) / maxPenalty; // Efficient operation count
                if (operations > maxOperations) return false; // Early exit for infeasibility
            }
            return true;
        };
        
        // Binary search
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