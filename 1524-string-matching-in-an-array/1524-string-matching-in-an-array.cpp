class Solution {
public:
vector<int> buildLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;  // length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP search to check if `pattern` is a substring of `text`
bool kmpSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = buildLPS(pattern);

    int i = 0;  // index for text
    int j = 0;  // index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            // Pattern found in text
            return true;
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false;
}
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
    int n = words.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && kmpSearch(words[j], words[i])) {
                result.push_back(words[i]);
                break;  // No need to check further once it's confirmed
            }
        }
    }

    return result;
    }
};