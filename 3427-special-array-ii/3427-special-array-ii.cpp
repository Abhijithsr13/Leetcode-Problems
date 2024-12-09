class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<bool> result;
        result.reserve(queries.size());

        // Step 1: Process each query independently
        for (const auto& query : queries) {
            int from = query[0], to = query[1];
            bool isSpecial = true;

            // Step 2: Check adjacent pairs in the range [from, to]
            for (int i = from; i < to; ++i) {
                if (nums[i] % 2 == nums[i + 1] % 2) {
                    isSpecial = false;
                    break; // Early exit if invalid pair is found
                }
            }

            result.push_back(isSpecial);
        }

        return result;
    }
};