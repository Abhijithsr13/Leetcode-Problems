class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diffArray(n + 1, 0);

        // Step 1: Update the difference array
        for (auto shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            int val = (direction == 1) ? 1 : -1;

            diffArray[start] += val;       // Increment at the start of the range
            if (end + 1 < n) {
                diffArray[end + 1] -= val; // Decrement just after the range
            }
        }

        // Step 2: Compute the prefix sum for cumulative shifts
        for (int i = 1; i < n; i++) {
            diffArray[i] += diffArray[i - 1];
        }

        // Step 3: Apply the shifts to the string
        for (int i = 0; i < n; i++) {
            int shift = diffArray[i];
            int newChar = ((s[i] - 'a' + shift) % 26 + 26) % 26; // Handle wrapping
            s[i] = 'a' + newChar;
        }

        return s;
    }
};