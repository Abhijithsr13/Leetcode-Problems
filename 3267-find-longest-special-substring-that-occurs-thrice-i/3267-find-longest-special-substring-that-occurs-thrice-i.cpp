class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int longestLength = -1;

        // Iterate over all possible lengths of substrings
        for (int k = 1; k <= n; ++k) {
            unordered_map<string, int> countMap;

            // Sliding window to count substrings of length k
            for (int i = 0; i <= n - k; ++i) {
                string substring = s.substr(i, k);

                // Check if the substring is special (all characters are
                // identical)
                bool isSpecial = true;
                for (int j = 1; j < k; ++j) {
                    if (substring[j] != substring[0]) {
                        isSpecial = false;
                        break;
                    }
                }

                if (isSpecial) {
                    countMap[substring]++;
                }
            }

            // Check for the longest special substring occurring at least three
            // times
            for (const auto& entry : countMap) {
                if (entry.second >= 3) {
                    longestLength = max(longestLength, k);
                }
            }
        }

        return longestLength;
    }
};