class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        const int numSpaces = spaces.size(); // Number of spaces to add
        const int originalLength =s.size(); // Length of the original string
        string result(originalLength + numSpaces,' '); // Initialize the result string with enough space

        int spaceIndex = 0; // Pointer for spacePositions
        for (int i = 0; i < originalLength; i++) {
            if (spaceIndex < numSpaces && i == spaces[spaceIndex]) {
                result[i + spaceIndex] =
                    ' ';      // Add a space at the correct position
                spaceIndex++; // Move to the next space index
            }
            result[i + spaceIndex] =s[i]; // Add the character from the original string
        }
        return result; // Return the resulting string
    }
};