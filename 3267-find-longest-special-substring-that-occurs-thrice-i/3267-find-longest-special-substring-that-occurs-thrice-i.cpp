class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
    if (n < 3) return -1; // No substring can appear at least three times

    int longestLength = -1;

    // Iterate over possible lengths of substrings
    for (int k = 1; k <= n; ++k) {
        unordered_map<string, int> countMap;
        int validCount = 0;

        // Use a sliding window to extract substrings of length k
        for (int i = 0; i <= n - k; ++i) {
            string substring = s.substr(i, k);

            // Check if the substring is "special" (all characters are identical)
            bool isSpecial = true;
            for (int j = 1; j < k; ++j) {
                if (substring[j] != substring[0]) {
                    isSpecial = false;
                    break;
                }
            }

            if (isSpecial) {
                countMap[substring]++;
                if (countMap[substring] == 3) { // Found at least 3 occurrences
                    validCount++;
                    longestLength = max(longestLength, k);
                }
            }
        }

        // Early exit if no substring of length k is valid
        if (validCount == 0) break;
    }

    return longestLength;
    }
};