class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
    int maxFreq = 0;
    int l = 0, r = 0; 
    int hash[26] = {0};  

    while (r < s.size()) {
        hash[s[r] - 'A']++;
        maxFreq = max(maxFreq, hash[s[r] - 'A']); 
        
        if ((r - l + 1) - maxFreq > k) {
            hash[s[l] - 'A']--;  
            l++; 
        }
        
        maxLen = max(maxLen, r - l + 1);
        r++;
    }

    return maxLen;
    }
};