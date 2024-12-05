class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // Skip blank spaces in both strings
            while (i < n && start[i] == '_')
                i++;
            while (j < n && target[j] == '_')
                j++;

            // Check if both strings have reached the end
            if (i == n && j == n)
                return true;

            // Check if one string ends before the other
            if (i == n || j == n)
                return false;

            // Check if the characters at the current positions are different
            if (start[i] != target[j])
                return false;

            // Check if 'L' or 'R' pieces follow the movement rules
            if (start[i] == 'L' && i < j)
                return false;
            if (start[i] == 'R' && i > j)
                return false;

            // Move to the next character
            i++;
            j++;
        }
        return true;
    }
};