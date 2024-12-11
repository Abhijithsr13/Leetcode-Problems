class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
    int maxBeauty = 0;
    int start = 0;
    for (int end = 0; end < nums.size(); ++end) {
        while (nums[end] - nums[start] > 2 * k) {
            ++start;
        }
        maxBeauty = max(maxBeauty, end - start + 1);
    }

    return maxBeauty;
    }
};