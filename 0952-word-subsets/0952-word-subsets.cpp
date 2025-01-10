class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0); // To store the maximum frequency of each character across all words in words2

    // Calculate the maximum frequency of each character across all words in words2
    for (const string& word : words2) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            maxFreq[i] = max(maxFreq[i], freq[i]);
        }
    }

    vector<string> result;

    // Check each word in words1
    for (const string& word : words1) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        bool universal = true;
        for (int i = 0; i < 26; i++) {
            if (freq[i] < maxFreq[i]) {
                universal = false;
                break;
            }
        }

        if (universal) {
            result.push_back(word);
        }
    }

    return result;
    }
};