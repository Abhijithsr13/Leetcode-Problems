class Solution {
public:
    string minWindow(string s, string t) {
         unordered_map<char, int> requiredChars;
    int formedChars = 0;
    int left = 0, right = 0;
    int minLen = INT_MAX;
    int minWindowStart = 0;

    // Initialize the required characters count
    for (char ch : t) {
        requiredChars[ch]++;
    }

    while (right < s.length()) {
        // Expand the window
        if (requiredChars.find(s[right]) != requiredChars.end()) {
            requiredChars[s[right]]--;
            if (requiredChars[s[right]] >= 0) {
                formedChars++;
            }
        }

        // Contract the window
        while (formedChars == t.length()) {
            // Update the minimum window substring
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minWindowStart = left;
            }

            // Shrink the window
            if (requiredChars.find(s[left]) != requiredChars.end()) {
                requiredChars[s[left]]++;
                if (requiredChars[s[left]] > 0) {
                    formedChars--;
                }
            }

            left++;
        }

        right++;
    }
    return minLen == INT_MAX ? "" : s.substr(minWindowStart, minLen);
    }
};