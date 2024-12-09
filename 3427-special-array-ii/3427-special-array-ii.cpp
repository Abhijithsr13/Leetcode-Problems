class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
          int n = nums.size();
    vector<int> prefixInvalid(n, 0); // Prefix sum for invalid pairs

    // Step 1: Compute prefixInvalid
    for (int i = 1; i < n; ++i) {
        prefixInvalid[i] = prefixInvalid[i - 1] + (nums[i - 1] % 2 == nums[i] % 2 ? 1 : 0);
    }

    // Step 2: Answer each query in O(1)
    vector<bool> result;
    result.reserve(queries.size());
    for (const auto& query : queries) {
        int from = query[0], to = query[1];
        // Check invalid pairs in range [from, to-1]
        result.push_back(prefixInvalid[to] - prefixInvalid[from] == 0);
    }

    return result;
    }
};