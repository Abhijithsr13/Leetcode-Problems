class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;

    while (i < str1.size() && j < str2.size()) {
        // Match directly
        if (str1[i] == str2[j]) {
            j++;
        }
        // Match with a cyclic increment
        else if (((str1[i] - 'a' + 1) % 26 + 'a') == str2[j]) {
            j++;
        }
        // Move pointer i in any case
        i++;
    }

    // If we matched all of str2
    return j == str2.size();
}
};