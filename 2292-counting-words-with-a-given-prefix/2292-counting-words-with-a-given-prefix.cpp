class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
         int count = 0;
    int prefLen = pref.length();

    for (const string& word : words) {
        // Check if the word starts with the prefix
        if (word.substr(0, prefLen) == pref) {
            count++;
        }
    }

    return count;
    }
};