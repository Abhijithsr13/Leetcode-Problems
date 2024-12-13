class Solution {
public:
    long long findScore(vector<int>& nums) {
    int n = nums.size();
    long long score = 0;

    vector<bool> marked(n, false);

    vector<pair<int, int>> valueIndex;
    for (int i = 0; i < n; ++i) {
        valueIndex.emplace_back(nums[i], i);
    }

    sort(valueIndex.begin(), valueIndex.end());

    for (const auto& [value, index] : valueIndex) {
        if (marked[index]) continue;

        score += value;

        marked[index] = true;
        if (index > 0) marked[index - 1] = true;
        if (index < n - 1) marked[index + 1] = true;
    }

    return score;
    }
};